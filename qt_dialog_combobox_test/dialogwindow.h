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

class DialogWindow : public QDialog
{
  Q_OBJECT

  public:
	  DialogWindow(QWidget * parent = 0);
  
  private:
	  QGridLayout * mgridlayout; // member grid layout
	  
	  QComboBox * mcombobox; // member combobox
	  QLabel * mlabel; // member label
	  QDialogButtonBox * mdialogbtnbox; // member dialogbuttonbox
  
  public slots:
	  void mSlot(int idx);

  private slots:
	  void acceptedSlot();
          void rejectedSlot();


  protected:
	  virtual void closeEvent(QCloseEvent *); // override fc ( nb: seems to work with 'protected' & with/without 'virtual' in front of it ( ... ) )
};

#endif // DIALOGWINDOW_H
