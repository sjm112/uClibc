/* vi: set sw=4 ts=4: */
/*
 * rmdir() for uClibc
 *
 * Copyright (C) 2000-2006 Erik Andersen <andersen@uclibc.org>
 *
 * Licensed under the LGPL v2.1, see the file COPYING.LIB in this tarball.
 */

#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>


#if defined(__NR_unlinkat) && !defined(__NR_rmdir)
int rmdir(const char *pathname)
{
	return unlinkat(AT_FDCWD, pathname, AT_REMOVEDIR);
}
#else
_syscall1(int, rmdir, const char *, pathname)
#endif
libc_hidden_def(rmdir)
