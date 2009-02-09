/*
	------------------------------------------------------------------------------------
	LICENSE:
	------------------------------------------------------------------------------------
	This file is part of EVEmu: EVE Online Server Emulator
	Copyright 2006 - 2008 The EVEmu Team
	For the latest information visit http://evemu.mmoforge.org
	------------------------------------------------------------------------------------
	This program is free software; you can redistribute it and/or modify it under
	the terms of the GNU Lesser General Public License as published by the Free Software
	Foundation; either version 2 of the License, or (at your option) any later
	version.

	This program is distributed in the hope that it will be useful, but WITHOUT
	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
	FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with
	this program; if not, write to the Free Software Foundation, Inc., 59 Temple
	Place - Suite 330, Boston, MA 02111-1307, USA, or go to
	http://www.gnu.org/copyleft/lesser.txt.
	------------------------------------------------------------------------------------
	Author:		Zhur
*/

#include "EvemuPCH.h"

ShipDB::ShipDB(DBcore *db)
: ServiceDB(db)
{
}

ShipDB::~ShipDB() {
}

PyRepTuple *ShipDB::GetFormations() {
	//vicious crap... but this is gunna be a bit of work to load from the DB (nested tuples)
	PyRepTuple *res = new PyRepTuple(2);

	cache_Formation f;
	Call_PointArg pos;

	//Diamond formation
	f.name = "Diamond";
	f.positions = new PyRepTuple(4);

	pos.x = 100;	pos.y = 0;		pos.z = 0;
	f.positions->items[0] = pos.FastEncode();
	pos.x = 0;		pos.y = 100;	pos.z = 0;
	f.positions->items[1] = pos.FastEncode();
	pos.x = -100;	pos.y = 0;		pos.z = 0;
	f.positions->items[2] = pos.FastEncode();
	pos.x = 0;		pos.y = -100;	pos.z = 0;
	f.positions->items[3] = pos.FastEncode();

	res->items[0] = f.FastEncode();

	//Arrow formation
	f.name = "Arrow";
	f.positions = new PyRepTuple(4);

	pos.x = 100;	pos.y = 0;		pos.z = -50;
	f.positions->items[0] = pos.FastEncode();
	pos.x = 50;		pos.y = 0;		pos.z = 0;
	f.positions->items[1] = pos.FastEncode();
	pos.x = -100;	pos.y = 0;		pos.z = -50;
	f.positions->items[2] = pos.FastEncode();
	pos.x = -50;	pos.y = 0;		pos.z = 0;
	f.positions->items[3] = pos.FastEncode();

	res->items[1] = f.FastEncode();

	return(res);
}

