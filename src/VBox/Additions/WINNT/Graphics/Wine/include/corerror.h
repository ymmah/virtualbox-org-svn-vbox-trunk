/*
 * Copyright 2008 James Hawkins
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/*
 * Sun LGPL Disclaimer: For the avoidance of doubt, except that if any license choice
 * other than GPL or LGPL is available it will apply instead, Sun elects to use only
 * the Lesser General Public License version 2.1 (LGPLv2) at this time for any software where
 * a choice of LGPL license versions is made available with the language indicating
 * that LGPLv2 or any later version may be used, or where a choice of which version
 * of the LGPL is applied is otherwise unspecified.
 */

#ifndef __WINE_CORERROR_H
#define __WINE_CORERROR_H

#include <winerror.h>

#ifndef FACILITY_URT
#define FACILITY_URT 0x13
#endif

#ifndef EMAKEHR
#define SMAKEHR(val) MAKE_HRESULT(SEVERITY_SUCCESS, FACILITY_URT, val)
#define EMAKEHR(val) MAKE_HRESULT(SEVERITY_ERROR, FACILITY_URT, val)
#endif

#define COR_E_ARGUMENT              E_INVALIDARG
#define COR_E_INVALIDCAST           E_NOINTERFACE
#define COR_E_NULLREFERENCE         E_POINTER
#define COR_E_OUTOFMEMORY           E_OUTOFMEMORY
#define COR_E_UNAUTHORIZEDACCESS    E_ACCESSDENIED

#define COR_E_ARITHMETIC            HRESULT_FROM_WIN32(ERROR_ARITHMETIC_OVERFLOW)
#define COR_E_STACKOVERFLOW         HRESULT_FROM_WIN32(ERROR_STACK_OVERFLOW)
#define COR_E_ENDOFSTREAM           HRESULT_FROM_WIN32(ERROR_HANDLE_EOF)
#define COR_E_FILENOTFOUND          HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND)
#define COR_E_BAD_PATHNAME          HRESULT_FROM_WIN32(ERROR_BAD_PATHNAME)
#define COR_E_DIRECTORYNOTFOUND     HRESULT_FROM_WIN32(ERROR_PATH_NOT_FOUND)
#define COR_E_PATHTOOLONG           HRESULT_FROM_WIN32(ERROR_FILENAME_EXCED_RANGE)

#define COR_E_AMBIGUOUSMATCH    _HRESULT_TYPEDEF_(0x8000211DL)
#define COR_E_TARGETPARAMCOUNT  _HRESULT_TYPEDEF_(0x8002000EL)
#define COR_E_DIVIDEBYZERO      _HRESULT_TYPEDEF_(0x80020012L)
#define COR_E_BADIMAGEFORMAT    _HRESULT_TYPEDEF_(0x8007000BL)

#define COR_E_ASSEMBLYEXPECTED          EMAKEHR(0x1018L)
#define COR_E_TYPEUNLOADED              EMAKEHR(0x1013L)
#define COR_E_EXCEPTION                 EMAKEHR(0x1500L)
#define COR_E_SYSTEM                    EMAKEHR(0x1501L)
#define COR_E_ARGUMENTOUTOFRANGE        EMAKEHR(0x1502L)
#define COR_E_ARRAYTYPEMISMATCH         EMAKEHR(0x1503L)
#define COR_E_CONTEXTMARSHAL            EMAKEHR(0x1504L)
#define COR_E_TIMEOUT                   EMAKEHR(0x1505L)
#define COR_E_EXECUTIONENGINE           EMAKEHR(0x1506L)
#define COR_E_FIELDACCESS               EMAKEHR(0x1507L)
#define COR_E_INDEXOUTOFRANGE           EMAKEHR(0x1508L)
#define COR_E_INVALIDOPERATION          EMAKEHR(0x1509L)
#define COR_E_SECURITY                  EMAKEHR(0x150AL)
#define COR_E_REMOTING                  EMAKEHR(0x150BL)
#define COR_E_SERIALIZATION             EMAKEHR(0x150CL)
#define COR_E_VERIFICATION              EMAKEHR(0x150DL)
#define COR_E_SERVER                    EMAKEHR(0x150EL)
#define COR_E_SERVICEDCOMPONENT         EMAKEHR(0x150FL)
#define COR_E_METHODACCESS              EMAKEHR(0x1510L)
#define COR_E_MISSINGFIELD              EMAKEHR(0x1511L)
#define COR_E_MISSINGMEMBER             EMAKEHR(0x1512L)
#define COR_E_MISSINGMETHOD             EMAKEHR(0x1513L)
#define COR_E_MULTICASTNOTSUPPORTED     EMAKEHR(0x1514L)
#define COR_E_NOTSUPPORTED              EMAKEHR(0x1515L)
#define COR_E_OVERFLOW                  EMAKEHR(0x1516L)
#define COR_E_RANK                      EMAKEHR(0x1517L)
#define COR_E_SYNCHRONIZATIONLOCK       EMAKEHR(0x1518L)
#define COR_E_THREADINTERRUPTED         EMAKEHR(0x1519L)
#define COR_E_MEMBERACCESS              EMAKEHR(0x151AL)
#define COR_E_THREADSTATE               EMAKEHR(0x1520L)
#define COR_E_THREADSTOP                EMAKEHR(0x1521L)
#define COR_E_TYPELOAD                  EMAKEHR(0x1522L)
#define COR_E_ENTRYPOINTNOTFOUND        EMAKEHR(0x1523L)
#define COR_E_DLLNOTFOUND               EMAKEHR(0x1524L)
#define COR_E_THREADSTART               EMAKEHR(0x1525L)
#define COR_E_INVALIDCOMOBJECT          EMAKEHR(0x1527L)
#define COR_E_NOTFINITENUMBER           EMAKEHR(0x1528L)
#define COR_E_DUPLICATEWAITOBJECT       EMAKEHR(0x1529L)
#define COR_E_SEMAPHOREFULL             EMAKEHR(0x152BL)
#define COR_E_WAITHANDLECANNOTBEOPENED  EMAKEHR(0x152CL)
#define COR_E_ABANDONEDMUTEX            EMAKEHR(0x152DL)
#define COR_E_INVALIDOLEVARIANTTYPE     EMAKEHR(0x1531L)
#define COR_E_MISSINGMANIFESTRESOURCE   EMAKEHR(0x1532L)
#define COR_E_SAFEARRAYTYPEMISMATCH     EMAKEHR(0x1533L)
#define COR_E_TYPEINITIALIZATION        EMAKEHR(0x1534L)
#define COR_E_MARSHALDIRECTIVE          EMAKEHR(0x1535L)
#define COR_E_MISSINGSATELLITEASSEMBLY  EMAKEHR(0x1536L)
#define COR_E_FORMAT                    EMAKEHR(0x1537L)
#define COR_E_SAFEARRAYRANKMISMATCH     EMAKEHR(0x1538L)
#define COR_E_PLATFORMNOTSUPPORTED      EMAKEHR(0x1539L)
#define COR_E_INVALIDPROGRAM            EMAKEHR(0x153AL)
#define COR_E_OPERATIONCANCELED         EMAKEHR(0x153BL)
#define COR_E_INSUFFICIENTMEMORY        EMAKEHR(0x153DL)
#define COR_E_RUNTIMEWRAPPED            EMAKEHR(0x153EL)
#define COR_E_DEVICESNOTSUPPORTED       EMAKEHR(0x1540L)
#define COR_E_DATAMISALIGNED            EMAKEHR(0x1541L)
#define COR_E_KEYNOTFOUND               EMAKEHR(0x1577L)
#define COR_E_APPLICATION               EMAKEHR(0x1600L)
#define COR_E_INVALIDFILTERCRITERIA     EMAKEHR(0x1601L)
#define COR_E_REFLECTIONTYPELOAD        EMAKEHR(0x1602L)
#define COR_E_TARGET                    EMAKEHR(0x1603L)
#define COR_E_TARGETINVOCATION          EMAKEHR(0x1604L)
#define COR_E_CUSTOMATTRIBUTEFORMAT     EMAKEHR(0x1605L)
#define COR_E_IO                        EMAKEHR(0x1620L)
#define COR_E_FILELOAD                  EMAKEHR(0x1621L)
#define COR_E_OBJECTDISPOSED            EMAKEHR(0x1622L)
#define COR_E_FAILFAST                  EMAKEHR(0x1623L)
#define COR_E_HOSTPROTECTION            EMAKEHR(0x1640L)
#define COR_E_ILLEGAL_REENTRANCY        EMAKEHR(0x1641L)

#define FUSION_E_INVALID_NAME           EMAKEHR(0x1047)

#define CLDB_E_FILE_OLDVER              EMAKEHR(0x1107)

#endif	/* __WINE_CORERROR_H */
