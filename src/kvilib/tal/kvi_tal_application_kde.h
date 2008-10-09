#ifndef _KVI_TAL_APPLICATION_KDE_H_
#define _KVI_TAL_APPLICATION_KDE_H_
//=============================================================================
//
//   File : kvi_tal_application_kde.h
//   Creation date : Sun Aug 12 2001 04:32:08 by Szymon Stefanek
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2001-2008 Szymon Stefanek (pragma at kvirc dot net)
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc. ,59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
//=============================================================================

/**
* \file kvi_tal_application_kde.h
* \author Szymon Stefanek
* \brief KDE class for application
*/

#include "kvi_settings.h"

#include <KApplication>

/**
* \class KviTalApplication
* \brief Toolkit Abstraction Layer: application class
*/
class KVILIB_API KviTalApplication : public KApplication
{
	Q_OBJECT
public:
	/**
	* \brief Constructs the application object
	* \param iArgc The number of arguments
	* \param ppcArgv The arguments list
	* \return KviTalApplication
	*/
	KviTalApplication(int & iArgc, char ** ppcArgv);

	/**
	* \brief Destroys the application object
	*/
	~KviTalApplication();
};

#endif // _KVI_TAL_APPLICATION_KDE_H_
