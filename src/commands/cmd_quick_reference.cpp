/* ASE - Allegro Sprite Editor
 * Copyright (C) 2001-2010  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "config.h"

#include <allegro.h>

#include "commands/command.h"
#include "core/dirs.h"
#include "launcher.h"

//////////////////////////////////////////////////////////////////////
// about

class QuickReferenceCommand : public Command
{
public:
  QuickReferenceCommand();
  Command* clone() const { return new QuickReferenceCommand(*this); }

protected:
  void execute(Context* context);
};

QuickReferenceCommand::QuickReferenceCommand()
  : Command("quick_reference",
	    "Quick Reference",
	    CmdUIOnlyFlag)
{
}

void QuickReferenceCommand::execute(Context* context)
{
  DIRS* dirs = filename_in_docsdir("quickref.pdf");

  for (DIRS* dir=dirs; dir; dir=dir->next) {
    if (!exists(dir->path))
      continue;

    Launcher::openFile(dir->path);
    break;
  }

  dirs_free(dirs);
}

//////////////////////////////////////////////////////////////////////
// CommandFactory

Command* CommandFactory::create_quick_reference_command()
{
  return new QuickReferenceCommand;
}
