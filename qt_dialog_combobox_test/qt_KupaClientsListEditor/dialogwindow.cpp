/* dialogwindow.cpp */

#include "dialogwindow.h"

DialogWindow::DialogWindow(QWidget * parent) : QDialog(parent)
{
  mgridlayout = new QGridLayout(this);
  mlabel = new QLabel("-");

  mcombobox = new QComboBox();

  // test-implm: add std buttons to the QDialog using a QDialogButtonBox
  mdialogbtnbox = new QDialogButtonBox(Qt::Horizontal);
  mdialogbtnbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

  // connect the signals emitted form the QDialogButtonBox to the appropriate slots ( here, 'accepted()' & 'rejected()', as we use standard buttons and not QPushButtons inside the QDialogButtonBox )
  connect( mdialogbtnbox, SIGNAL(accepted()), this, SLOT(acceptedSlot()) );
  connect( mdialogbtnbox, SIGNAL(rejected()), this, SLOT(rejectedSlot()) );

  // fill the commbo box with stuff
  mcombobox->addItem("AAA");
  mcombobox->addItem("CCC");
  mcombobox->addItem("GGG");
  mcombobox->addItem("TTT");

  // connect the 'activated' signal ( aka when the combobox selection changes ) to the appropriate slot
  QObject::connect( mcombobox, SIGNAL(activated(int)), this, SLOT(mSlot(int)) );

  // add widgets to the dialog window
  mgridlayout->addWidget(mcombobox, 0, 0, Qt::AlignLeft);
  mgridlayout->addWidget(mlabel, 1, 0, Qt::AlignLeft);
  mgridlayout->addWidget(mdialogbtnbox, 2, 0, Qt::AlignLeft);
  
  setMinimumSize(250, 150); // specify a minimum size for the dialog window
  //resize(50, 200);
  //setFixedSize(350, 100);

}

/* the slot that will read the input & do stg with it */
void DialogWindow::mSlot(int idx)
{
  mlabel->setText(mcombobox->itemText(idx)); // set the selected combobox item text as the label text
}

/* overriding the 'closeEvent()' SLOT */
void DialogWindow::closeEvent(QCloseEvent *event)
{
  //if (  {
  //  writeSettings();
  //    event->accept(); // close window
  //} else {
  //    event->ignore(); // keep window
  //}
  
  qDebug() << "user chosed to close the window with neither accepting nor rejecting" << endl;
  event->accept();

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
