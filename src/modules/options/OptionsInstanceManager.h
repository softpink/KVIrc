

#ifndef __OPTIONS_INSTANCES_H__
#define __OPTIONS_INSTANCES_H__

//=============================================================================
//
//   File : OptionsInstanceManager.h
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
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================

//
// Instance creation routines for the KVIrc options module
// DO NOT EDIT THIS FILE!! ALL CHANGES WILL BE LOST!!
// This file is automatically generated by mkcreateinstanceproc.sh
// so any change should go in that script
//

#include "KviOptionsWidget.h"
#include "KviModule.h"
#include "KviPointerList.h"
#include "KviQString.h"
#include "KviIconManager.h"

typedef struct _OptionsWidgetInstanceEntry OptionsWidgetInstanceEntry;


typedef struct _OptionsWidgetInstanceEntry
{
	KviOptionsWidget                           * (*createProc)(QWidget *);
	KviOptionsWidget                           * pWidget;   // singleton
	KviIconManager::SmallIcon                    eIcon;
	QString                                      szName;
	QString                                      szNameNoLocale;
	const char                                 * szClassName;
	int                                          iPriority;
	QString                                      szKeywords;
	QString                                      szKeywordsNoLocale;
	QString                                      szGroup;
	bool                                         bIsContainer;
	bool                                         bIsNotContained;
	KviPointerList<OptionsWidgetInstanceEntry> * pChildList;
	bool                                         bDoInsert; // a helper for OptionsDialog::fillListView()
} OptionsWidgetInstanceEntry;


class OptionsInstanceManager : public QObject
{
	Q_OBJECT
public:
	OptionsInstanceManager();
	virtual ~OptionsInstanceManager();
protected:
	KviPointerList<OptionsWidgetInstanceEntry> * m_pInstanceTree;
public:
	KviPointerList<OptionsWidgetInstanceEntry> * instanceEntryTree(){ return m_pInstanceTree; };
	KviOptionsWidget * getInstance(OptionsWidgetInstanceEntry * pEntry, QWidget * pPar);
	OptionsWidgetInstanceEntry * findInstanceEntry(const char * pcName);
	void cleanup(KviModule *);
protected:
	OptionsWidgetInstanceEntry * findInstanceEntry(const char * pcName, KviPointerList<OptionsWidgetInstanceEntry> * pList);
	OptionsWidgetInstanceEntry * findInstanceEntry(const QObject * pObj, KviPointerList<OptionsWidgetInstanceEntry> * pList);
	void deleteInstanceTree(KviPointerList<OptionsWidgetInstanceEntry> * pList);
protected slots:
	void widgetDestroyed();
};

#endif //__OPTIONS_INSTANCES_H__
