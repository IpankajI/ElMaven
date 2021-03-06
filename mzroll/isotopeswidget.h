#ifndef ISOTOPEWIDGETGUI_H
#define ISOTOPEWIDGETGUI_H

#include "stable.h"
#include "mzSample.h"
#include "mainwindow.h"
#include "background_peaks_update.h"
#include "ui_isotopeswidget.h"
#include "numeric_treewidgetitem.h"
#include "../libmaven/isotopelogic.h"

class QAction;
class QMenu;
class QTextEdit;
class MainWindow;

using namespace std;

class IsotopeWidget: public QDockWidget, public Ui_isotopesWidget {
Q_OBJECT

public:
	IsotopeWidget(MainWindow*);
	~IsotopeWidget();
	BackgroundPeakUpdate* workerThread;

 	BackgroundPeakUpdate* workerThreadBarplot;


public Q_SLOTS:
	void setCharge(double charge);
	void setFormula(QString f);
	void userChangedFormula(QString f);
	void computeIsotopes(string f);
	void setPeakGroupAndMore(PeakGroup* grp, bool bookmarkflg);
	void setCompound(Compound* compound);
	void setIonizationMode(int mode);
	void setPeak(Peak* peak);
	void setClipboard();
	void setClipboard(PeakGroup* group);
	void setClipboard(QList<PeakGroup*>& groups);
	void pullIsotopes(PeakGroup* group);
	void pullIsotopesForBarplot(PeakGroup* group);
	void updateIsotopicBarplot(PeakGroup* grp);
	void updateIsotopicBarplot();
	Peak* getSamplePeak(PeakGroup* group, mzSample* sample);

private Q_SLOTS:
	void showInfo();
	void showTable();
	QString groupTextEport(PeakGroup* group);

private:
	  IsotopeLogic* isotopeParameters;
	  IsotopeLogic* isotopeParametersBarPlot;
      MainWindow* _mw;
	  bool bookmarkflag;

     QString groupIsotopeMatrixExport(PeakGroup* group, bool includeSampleHeader); //TODO: Changed the structure of the function while merging isotopewidget

};

#endif
