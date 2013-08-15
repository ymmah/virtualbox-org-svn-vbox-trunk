/* $Id$ */
/** @file
 * IPRT R0 Testcase - Timers, driver program.
 */

/*
 * Copyright (C) 2009-2010 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 *
 * The contents of this file may alternatively be used under the terms
 * of the Common Development and Distribution License Version 1.0
 * (CDDL) only, as it comes in the "COPYING.CDDL" file of the
 * VirtualBox OSE distribution, in which case the provisions of the
 * CDDL are applicable instead of those of the GPL.
 *
 * You may elect to license modified versions of this file under the
 * terms and conditions of either the GPL or the CDDL or both.
 */

/*******************************************************************************
*   Header Files                                                               *
*******************************************************************************/
#include <iprt/initterm.h>

#include <iprt/err.h>
#include <iprt/path.h>
#include <iprt/param.h>
#include <iprt/stream.h>
#include <iprt/string.h>
#include <iprt/test.h>
#include <iprt/thread.h>
#ifdef VBOX
# include <VBox/sup.h>
# include "tstRTR0Timer.h"
#endif
#include "tstRTR0CommonDriver.h"


int main(int argc, char **argv)
{
#ifndef VBOX
    RTPrintf("tstRTR0Timer: SKIPPED\n");
    return RTEXITCODE_SKIPPED;
#else
    /*
     * Init.
     */
    RTEXITCODE rcExit = RTR3TestR0CommonDriverInit("tstRTR0Timer");
    if (rcExit != RTEXITCODE_SUCCESS)
        return rcExit;

# if 1
    /*
     * Standard timers.
     */
#  ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
    RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_BASIC,       "Basic one shot");
#  endif
    RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_BASIC,       "Basic periodic");
    if (RTTestErrorCount(g_hTest) == 0)
    {
#  if 1
#   ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_RESTART, "Restart one shot from callback");
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_DESTROY, "Destroy one shot from callback");
#   endif
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_CSSD_LOOPS, "Create-start-stop-destroy loops");
        for (uint32_t i = 0; i <= 7; i++)
            RTR3TestR0SimpleTestWithArg(TSTRTR0TIMER_PERIODIC_CHANGE_INTERVAL, i, "Change interval from callback, variation %u", i);
#  endif
#   ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_SPECIFIC, "One shot cpu specific");
#   endif
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_SPECIFIC, "Periodic cpu specific");
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_OMNI, "Periodic omni timer");
    }
# endif

# if 1
    /*
     * High resolution timers.
     */
#  ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
    RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_BASIC_HIRES, "Basic hires one shot");
#  endif
    RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_BASIC_HIRES, "Basic hires periodic");
    if (RTTestErrorCount(g_hTest) == 0)
    {
#  if 1
#   ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_RESTART_HIRES, "Restart hires one shot from callback");
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_DESTROY_HIRES, "Destroy hires one shot from callback");
#   endif
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_CSSD_LOOPS_HIRES, "Create-start-stop-destroy loops, hires");
        for (uint32_t i = 0; i <= 7; i++)
            RTR3TestR0SimpleTestWithArg(TSTRTR0TIMER_PERIODIC_CHANGE_INTERVAL, i, "Change interval from callback, hires, variation %u", i);
#  endif
#   ifndef RT_OS_SOLARIS // one-shot timers currently not supported on Solaris
        RTR3TestR0SimpleTest(TSTRTR0TIMER_ONE_SHOT_SPECIFIC_HIRES, "One shot hires cpu specific");
#   endif
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_SPECIFIC_HIRES, "Periodic hires cpu specific");
        RTR3TestR0SimpleTest(TSTRTR0TIMER_PERIODIC_OMNI, "Periodic omni hires timer");
    }
# endif

    /*
     * Done.
     */
    return RTTestSummaryAndDestroy(g_hTest);
#endif
}

