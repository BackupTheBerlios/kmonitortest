/***************************************************************************
                          kmonitortest.h  -  description
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
#ifndef KMONITORTEST_H_
#define KMONITORTEST_H_

#include <kcmodule.h>
#include <kaboutdata.h>

class QGroupBox;
class QListView;
class QPushButton;
class QLabel;
class QTextEdit;   

class KMonitorTest: public KCModule
{
   Q_OBJECT
   public:
      KMonitorTest(QWidget *parent = 0L, const char *name = 0L);
      virtual ~KMonitorTest();

      void load();
      void save();
      void defaults();
      int buttons();
      QString quickHelp() const;
      const KAboutData* aboutData() {return myAboutData; };

   protected slots:
      void slotShow();
      
   public slots:
      void configChanged();

   protected:
      void UserInterface();

   protected:
      QGroupBox   *mTestGroup;
      QListView   *mTestListView; 
      QPushButton *mShowBt; 
      QLabel      *mMonitorLabel; 
      QGroupBox   *mHelpGroup; 
      QTextEdit   *mHelpText;

      int         mSelected;
      
   private:
      KAboutData *myAboutData;
};

#endif
