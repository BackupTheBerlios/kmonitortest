/***************************************************************************
                          kmonitortest.cpp  -  description
                             -------------------
    begin                : Tue May  6 21:39:51 CEST 2003
    copyright            : (C) 2003 by Michael v.Ostheim, Pierre Jarillon
    email                : ostheimm@users.berlios.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#include <qlayout.h>

#include <klocale.h>
#include <kglobal.h>
#include <kstandarddirs.h>

#include <qgroupbox.h>
#include <qlistview.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qwhatsthis.h>
#include <qheader.h>
#include <qtextedit.h>

#include "kmonitortest.h"

KMonitorTest::KMonitorTest(QWidget *parent, const char *name) \
  :KCModule(parent,name)
{
  UserInterface();
  load();
};


KMonitorTest::~KMonitorTest() {
}

void KMonitorTest::UserInterface() {
  // Parts of the following code was taken from KScreenSaver
      
  QBoxLayout *topLayout = new QVBoxLayout(this, 10, 10);

  QBoxLayout *helperLayout = new QHBoxLayout(topLayout, 10);

  // left column
  QBoxLayout *vLayout = new QVBoxLayout(helperLayout, 10);

  mTestGroup = new QGroupBox(i18n("Test Pictures"), this );
  vLayout->addWidget(mTestGroup);
  QBoxLayout *groupLayout = new QVBoxLayout( mTestGroup, 10 );
  groupLayout->addSpacing(10);

  mTestListView = new QListView( mTestGroup );
  mTestListView->addColumn("");
  mTestListView->header()->hide();
  mSelected = -1;
  groupLayout->addWidget( mTestListView, 10 );
  QWhatsThis::add( mTestListView, i18n("This is a list of the available"
   " test pictures. Select the one you want to use.") );

  QBoxLayout* hlay = new QHBoxLayout(groupLayout, 10);
  mShowBt = new QPushButton(  i18n("&Show..."), mTestGroup );
  connect( mShowBt, SIGNAL( clicked() ), SLOT( slotShow() ) );
  mShowBt->setEnabled(false);
  hlay->addWidget( mShowBt );
  QWhatsThis::add( mShowBt, i18n("You can show the selected test picture"
    " by clicking this button.") );

  // right column
  vLayout = new QVBoxLayout(helperLayout, 10);

  mMonitorLabel = new QLabel( this );
  mMonitorLabel->setAlignment( AlignCenter );
  mMonitorLabel->setPixmap( QPixmap(locate("data",
                       "kmonitortest/pics/monitor.png")));
  vLayout->addWidget(mMonitorLabel, 0);
  QWhatsThis::add( mMonitorLabel, i18n("Here you can see a preview of the"
    " selected test picture.") );

  mHelpGroup = new QGroupBox( i18n("Quick Help"), this );
  vLayout->addWidget( mHelpGroup );
  QBoxLayout *groupLayout2 = new QVBoxLayout( mHelpGroup, 10 );
  groupLayout2->addSpacing(10);
  
  mHelpText = new QTextEdit( mHelpGroup );
  groupLayout2->addWidget( mHelpText, 10 );
  mHelpText->setReadOnly(true);
}

void KMonitorTest::load() {
        // insert your loading code here...
}

void KMonitorTest::defaults() {
        // insert your default settings code here...
  emit changed(true);
}

void KMonitorTest::save() {
        // insert your saving code here...
  emit changed(true);
}

int KMonitorTest::buttons () {
        return KCModule::Help;
}

void KMonitorTest::configChanged() {
        // insert your saving code here...
        emit changed(true);
}

void KMonitorTest::slotShow() {

}

QString KMonitorTest::quickHelp() const
{
         return i18n("Helpful information about the kmonitortest module."); 
}

// ------------------------------------------------------------------------

extern "C"
{

        KCModule *create_kmonitortest(QWidget *parent, const char *name)
        {
                KGlobal::locale()->insertCatalogue("kmonitortest");
                return new KMonitorTest(parent, name);
        }
}

#include "kmonitortest.moc"
