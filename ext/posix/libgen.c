/***
@module posix
*/
/*
 * POSIX library for Lua 5.1/5.2.
 * (c) Gary V. Vaughan <gary@vaughan.pe>, 2013-2014
 * (c) Reuben Thomas <rrt@sc3d.org> 2010-2013
 * (c) Natanael Copa <natanael.copa@gmail.com> 2008-2010
 * Clean up and bug fixes by Leo Razoumov <slonik.az@gmail.com> 2006-10-11
 * Luiz Henrique de Figueiredo <lhf@tecgraf.puc-rio.br> 07 Apr 2006 23:17:49
 * Based on original by Claudio Terra for Lua 3.x.
 * With contributions by Roberto Ierusalimschy.
 * With documentation from Steve Donovan 2012
 */

#include <config.h>

#include <libgen.h>

#include "_helpers.h"


/***
General Library Functions.
@section libgen
*/


/***
File part of path.
@function basename
@string path file to act on
@treturn string filename part of *path*
@see basename(3)
*/
static int
Pbasename(lua_State *L)
{
	char *b;
	size_t len;
	void *ud;
	lua_Alloc lalloc;
	const char *path = luaL_checklstring(L, 1, &len);
	size_t path_len;
	checknargs(L, 1);
	path_len = strlen(path) + 1;
	lalloc = lua_getallocf(L, &ud);
	if ((b = lalloc(ud, NULL, 0, path_len)) == NULL)
		return pusherror(L, "lalloc");
	lua_pushstring(L, basename(strcpy(b,path)));
	lalloc(ud, b, path_len, 0);
	return 1;
}


/***
Directory name of path.
@function dirname
@string path file to act on
@treturn string directory part of *path*
@see dirname(3)
*/
static int
Pdirname(lua_State *L)
{
	char *b;
	size_t len;
	void *ud;
	lua_Alloc lalloc;
	const char *path = luaL_checklstring(L, 1, &len);
	size_t path_len;
	checknargs(L, 1);
	path_len = strlen(path) + 1;
	lalloc = lua_getallocf(L, &ud);
	if ((b = lalloc(ud, NULL, 0, path_len)) == NULL)
		return pusherror(L, "lalloc");
	lua_pushstring(L, dirname(strcpy(b,path)));
	lalloc(ud, b, path_len, 0);
	return 1;
}
