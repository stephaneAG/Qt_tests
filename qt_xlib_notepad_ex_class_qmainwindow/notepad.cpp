/* notepad.c - simple example of Notepad using a class - by StephaneAG - 2013  */
#include "notepad.h"

/* Notepad's constructor */
Notepad::Notepad()
{
	openAction = new QAction(tr("&Open"), this);
	saveAction = new QAction(tr("&Save"), this);
	exitAction = new QAction(tr("E&xit"), this);

	//quitButton = new QPushButton(tr("Quit"));

	//connect( quitButton, SIGNAL( clicked() ), this, SLOT( quit() ) );
	connect( openAction, SIGNAL( triggered() ), this, SLOT( open()) );
	connect( saveAction, SIGNAL( triggered() ), this, SLOT( save()) );
	connect( exitAction, SIGNAL( triggered() ), qApp, SLOT( quit()) );

	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAction);
	fileMenu->addAction(saveAction);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAction);

	//QVBoxLayout *layout = new QVBoxLayout;
	//layout->addWidget(textEdit);
	//layout->addWidget(quitButton);

	//setLayout(layout);
	textEdit = new QTextEdit;	
	setCentralWidget(textEdit);	

	setWindowTitle(tr("Notepad"));
}


/* the 'open()' SLOT */
void Notepad::open()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt);;C++ File (*.cpp *.h)"));
	
	if (fileName != ""){
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)){
			QMessageBox::critical(this, tr("Error"), tr("Could not open the file"));
			return;
		}
		QTextStream in(&file);
		textEdit->setText(in.readAll());
		file.close();
	}
}


/* the 'save()' SLOT */
void Notepad::save()
{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                tr("Text Files (*.txt);;C++ File (*.cpp *.h)"));

        if (fileName != ""){
                QFile file(fileName);
                if (!file.open(QIODevice::WriteOnly)){
                        //QMessageBox::critical(this, tr("Error"), tr("Could not save the file"));
                        //return;
                } else {
                	QTextStream stream(&file);
                	stream << textEdit->toPlainText();
			stream.flush();
                	file.close();
		}
        }
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
