#include "QTIrrlichtOrbifordVis.h"
#include "VisEventListener.h"


QTIrrlichtOrbifordVis::QTIrrlichtOrbifordVis(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	irrWidget = ui.mirrlichtwidget;
	//m_visView.release();

	// Setup for the Irrlicht Widget
	// This is new code that was not in the file generated by QtCreate
	//irrWidget->setParent(ui.mirrlichtwidget);
	//irrWidget.setGeometry(160, 0, 800, 800);

	//connect(ui.mirrlichtwidget, SIGNAL(resized(QSize)), SLOT(irrWidgetResize(QSize)));

	irrWidget->installEventFilter(this);//used for mouse leave and enter events (can be used for any widget)
}

void QTIrrlichtOrbifordVis::setVisView(VisView * vis)
{
	//m_visView.reset(vis);
}

bool QTIrrlichtOrbifordVis::eventFilter(QObject *target, QEvent *event)
{
	if (event->type() == QEvent::Enter) {
		this->irrWidget->MouseInWidget = true;
	}
	if (event->type() == QEvent::Leave) {
		this->irrWidget->MouseInWidget = false;
		this->setFocus(Qt::ActiveWindowFocusReason);
		this->grabKeyboard();
		this->releaseKeyboard();
	}

	return QMainWindow::eventFilter(target, event);
}

void QTIrrlichtOrbifordVis::on_pushButton_stopAnimations_clicked()
{
	//core::vector3df scale(20.0, 20.0, 20.0);

	//if (m_visView->Model)
	//	m_visView->Model->setScale(scale);
	//m_visView->updateScaleInfo(m_visView->Model);

}

void QTIrrlichtOrbifordVis::irrWidgetResize(QSize size) {

	QString status = QString("width:%1 height:%2")
		.arg(size.width()).arg(size.height());

	ui.statusBar->showMessage(status, 5000);
	irrWidget->resize(size);
}


void QTIrrlichtOrbifordVis::on_pushButton_AddObj_clicked()
{
	QMessageBox::information(this, "Foo", "Bar");
}
