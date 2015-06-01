/* dialogwindow.h - simple QDialog subclass with an embbedded QComboBox */

#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H

#include <QtGui/QDialog>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QLabel>
#include <QGridLayout>
#include <QCloseEvent>

#include <QDebug>
//#include <QVBoxLayout>

class DialogWindow : public QDialog
{
  Q_OBJECT

  public:
	  DialogWindow(QWidget * parent = 0);
  
  private:
	  QGridLayout * mgridlayout; // member grid layout ( to layout the inner components of the dialog )
	  
	  //QComboBox * mcombobox; // member combobox // test code
	  //QLabel * mlabel; // member label // test code

	  // ---- Dialog REAL stuff ----
	  QLabel * mlabel_brief; // the label displaying a brief explanation on the purpose of the dialog box & what it does
	  QLabel * mlabel_selectOS; // the label preceeding the OS combobox
	  QLabel * mlabel_selectKupy; // the label preceeding the Kupa method combobox
	  QComboBox * mcombobox_OS; // the Combobox containg the supported Operating Systems
	  QComboBox * mcombobox_Kupy; // the kupy method to be used when using Kupa
	  QDialogButtonBox * mdialogbtnbox; // member dialogbuttonbox ( hold the standard buttons of the dialog )

	  // ---- main functions ----
	  void saveSettingsToNodeFile(); // updates settings in the Node file
	  void fillComboboxesWithSettingsFromNodeFile(); // load settings from Node file
	  void fillComboboxesWithSupportedSettings(); // populate the comboboxes
  
  public slots:
	  //void mSlot(int idx); // test code // triggered when the 'activated()' signal is emitted ( hence, when 'mcombobox's highlighted selection has just changed )

  private slots:
	  void mcombobox_OS_Slot(int index); // triggered when the 'activated()' signal is emitted when the 'mcombobox_OS' highlighted sleection changes
          void mcombobox_Kupy_Slot(int index); // triggered when the 'activated()' signal is emitted when the 'mcombobox_Kupy' highlighted sleection changes

	  // buttonbox buttons clicks handlers
	  void acceptedSlot(); // triggered when the user clicks the 'Ok' button of the buttonbox
          void rejectedSlot(); // triggered when the user clicks the 'Cancel' button of the buttonbox

	  // Escape key hit handler
          void reject(); // (virtual) triggered when the user hits the 'Escape' key

  protected:
	  void closeEvent(QCloseEvent *); // (virtual) override the function triggered when the user click the dialog's window's close button
	  //( nb: seems to work with 'protected' & with/without 'virtual' in front of it ( ... ) )
};

#endif // DIALOGWINDOW_H
