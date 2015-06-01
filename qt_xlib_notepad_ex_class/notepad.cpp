/* notepad.c - simple example of Notepad using a class - by StephaneAG - 2013  */
#include "notepad.h"

/* Notepad's constructor */
Notepad::Notepad()
{
	textEdit = new QTextEdit;
	quitButton = new QPushButton(tr("Quit"));

	connect( quitButton, SIGNAL( clicked() ), this, SLOT( quit() ) );

	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(textEdit);
	layout->addWidget(quitButton);

	setLayout(layout);

	setWindowTitle(tr("Notepad"));
}


/* the 'quit()' SLOT */
void Notepad::quit()
{
	QMessageBox messageBox;
	messageBox.setWindowTitle(tr("Notepad"));
	messageBox.setText(tr("Do you really want to quit ?"));
	messageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	messageBox.setDefaultButton(QMessageBox::No);
	if (messageBox.exec() == QMessageBox::Yes)
	    qApp->quit();
}
