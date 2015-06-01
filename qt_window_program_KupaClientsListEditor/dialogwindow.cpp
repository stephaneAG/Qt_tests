/* dialogwindow.cpp */

#include "dialogwindow.h"

DialogWindow::DialogWindow(QWidget * parent) : QDialog(parent)
{
  mgridlayout = new QGridLayout(this); // create the dialog layout
  mlabel_brief = new QLabel("This is the purpose of this dialog window, and this is what it does \n Eh Viva Kupa ! ( or Pushr ? ) "); // the label containing the brief
  mlabel_selectOS = new QLabel("Select OS"); // the label preceeding the OS combobox
  mlabel_selectKupy = new QLabel("Select Kupy method");  // the label preceeding the Kupy combobox
  mcombobox_OS = new QComboBox(); // the OS combobox
  mcombobox_Kupy = new QComboBox(); // the Kupy combobox
  
  // ---- Test Code below ----
  //mlabel = new QLabel("-"); // test code label
  //mcombobox = new QComboBox(); // test code
  // fill the commbo box with stuff
  //mcombobox->addItem("AAA");
  //mcombobox->addItem("CCC");
  //mcombobox->addItem("GGG");
  //mcombobox->addItem("TTT");
  
  // fill the OS & Kupy combobox with values ( will be in a fcn testing if the vlaue to be inserted already exist in the vombobox before actually adding it to the box ( ... )
  mcombobox_OS->addItem("Linux");
  mcombobox_OS->addItem("Mac");

  mcombobox_Kupy->addItem("direct");
  mcombobox_Kupy->addItem("twosteps");


  // ---- End Test Code ----

  // setup the dialogbuttonbox ( here we use std buttons )
  mdialogbtnbox = new QDialogButtonBox(Qt::Horizontal);
  mdialogbtnbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

  // connect the signals emitted form the QDialogButtonBox to the appropriate slots ( here, 'accepted()' & 'rejected()', as we use standard buttons and not QPushButtons inside the QDialogButtonBox )
  connect( mdialogbtnbox, SIGNAL(accepted()), this, SLOT(acceptedSlot()) ); // when clicking 'Ok'
  connect( mdialogbtnbox, SIGNAL(rejected()), this, SLOT(rejectedSlot()) ); // when clicking 'Cancel'
  //connect( mdialogbtnbox, SIGNAL(reject()), this, SLOT(reject()) ); // when hitting the 'Escape' key
  connect( mdialogbtnbox, SIGNAL(reject()), this, SLOT(rejectedSlot()) ); // when hitting the 'Escape' key

  // connect the 'activated' signals ( aka when one of the combobox highlighted selection changes ) to the appropriate slot
  //QObject::connect( mcombobox, SIGNAL(activated(int)), this, SLOT(mSlot(int)) );
  connect( mcombobox_OS, SIGNAL(activated()), this, SLOT(mcombobox_OS_Slot()) );
  connect( mcombobox_Kupy, SIGNAL(activated()), this, SLOT(mcombobox_Kupy_Slot()) );

  // add widgets to the dialog window
  //mgridlayout->addWidget(mcombobox, 0, 0, Qt::AlignLeft); // test code
  //mgridlayout->addWidget(mlabel, 1, 0, Qt::AlignLeft); // test code
  //mgridlayout->addWidget(mlabel_brief, 0, 0, 0, -1, Qt::AlignLeft); // call the overload version of the 'addWidget()' fcn that make the label span across all the columns on row 0
  //mgridlayout->addWidget(mlabel_brief, 0, 3, 0, -1, Qt::AlignLeft);
  //mgridlayout->addWidget(mlabel_selectOS, 4, 0, Qt::AlignLeft); // add the OS label using the normal version of the 'addWidget()' fcn
  //mgridlayout->addWidget(mcombobox_OS, 4, 1, Qt::AlignLeft); // add the OS combobox
  //mgridlayout->addWidget(mlabel_selectKupy, 4, 2, Qt::AlignLeft); // add the Kupy label
  //mgridlayout->addWidget(mcombobox_Kupy, 4, 3, Qt::AlignLeft); // add the Kupy combobox
  //mgridlayout->addWidget(mdialogbtnbox, 5, 0, Qt::AlignLeft);
  //mgridlayout->addWidget(mdialogbtnbox, 2, 0, 0, -1, Qt::AlignCenter); // spanning version to test different alignement fot the buttonbox // seems to make it buggy ( ... )

  mgridlayout->addWidget(mlabel_brief, 0, 0, 2, -1, Qt::AlignLeft);
  mgridlayout->addWidget(mlabel_selectOS, 3, 0, Qt::AlignRight); // add the OS label using the normal version of the 'addWidget()' fcn
  mgridlayout->addWidget(mcombobox_OS, 3, 1, Qt::AlignLeft); // add the OS combobox
  mgridlayout->addWidget(mlabel_selectKupy, 3, 2, Qt::AlignRight); // add the Kupy label
  mgridlayout->addWidget(mcombobox_Kupy, 3, 3, Qt::AlignLeft); // add the Kupy combobox
  mgridlayout->addWidget(mdialogbtnbox, 6, 3, Qt::AlignLeft);

  //setMinimumSize(350, 250); // specify a minimum size for the dialog window
  //resize(50, 200);
  //setFixedSize(350, 100);

}

// ---- Combobox-related SLOTS ----

/* the slot that will read the input & do stg with it */
//void DialogWindow::mSlot(int idx)
//{
//  mlabel->setText(mcombobox->itemText(idx)); // set the selected combobox item text as the label text
//}

/* the 'mcombobox_OS' SLOT  - gets triggered when the 'mcombobox_OS' selection has just been changed ( 'activated' for Qt ) */
void DialogWindow::mcombobox_OS_Slot(int index)
{
  qDebug() << "Currently selected Operating System for local Kupa Node: " << mcombobox_OS->itemText(index) << endl;
}

/* the 'mcombobox_Kupy' SLOT  - gets triggered when the 'mcombobox_Kupy' selection has just been changed ( 'activated' for Qt ) */
void DialogWindow::mcombobox_Kupy_Slot(int index)
{
  qDebug() << "Currently selected Kupy method for local Kupa Node: " << mcombobox_Kupy->itemText(index) << endl;
}


// ---- Close / Save / Cancel 'dialog events' SLOTS ----

/* overriding the 'closeEvent()' SLOT */
void DialogWindow::closeEvent(QCloseEvent *event)
{
  //if ( stg )  {
  //  writeSettings();
  //    event->accept(); // close window
  //} else {
  //    event->ignore(); // keep window
  //}
  
  qDebug() << "user chosed to close the window with neither accepting nor rejecting" << endl;
  event->accept();

}

/* the 'reject()' virtual SLOT */
void DialogWindow::reject()
{
  qDebug() << "User just hit Escape key" << endl;
  qDebug() << "yolo!"<< endl;
}
/* the 'accepted()' SLOT */
void DialogWindow::acceptedSlot()
{
  qDebug() << "accepted slot triggered" << endl;

  // do stuff as user just validated the changes he wished to make -> we could also popup a confirmation box ( ... )
  
  // close the current dialog window
  emit close(); // will it 'do the trick' ?
}
/* the 'rejected()' SLOT */
void DialogWindow::rejectedSlot()
{
  qDebug() << "rejected slot triggered" << endl;
}


// ---- Static Fcns ----

/* the 'saveSettingsToNodeFile()' fcn - updates the settings of the local Kupa Node by saving the comboboxes' current selection in the 'node_settings.kupa' file */
void DialogWindow::saveSettingsToNodeFile()
{
  
}

/* the 'fillComboboxesWithSettingsFromNodeFile()' - opens the 'node_settings.kupa' file & parses its content before appending it as the comboboxes' selected values ( appearing at the top / visible ) */
void DialogWindow::fillComboboxesWithSettingsFromNodeFile()
{
  
}

/* the 'fillComboboxesWithSupportedSettings()' - append the supported settings by Kupa to each combobox ( I guess using two separate 'QList' ) */
void DialogWindow::fillComboboxesWithSupportedSettings()
{
  
}
