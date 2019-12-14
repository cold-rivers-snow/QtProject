#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
class QSqlQuery;
class QTimer;
QT_END_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    bool connectMySQL();
    void upateMySQL();
    QStringList selectAppropriateData(const QString &cmd);

protected slots:
    void btnClicked();
    void sqlDataTimeout();

private:
    Ui::Widget *ui;
    QSqlDatabase m_db;
    QSqlQuery *m_query;
    QTimer *m_timer;
    bool m_isRun;
};

#endif // WIDGET_H
