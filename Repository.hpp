#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <QDir>
#include <QString>
#include <QStringList>

class Repository
{
public:
    Repository(const QDir& dir);
    template<class t_Callback> void getCategories(t_Callback callback) const;
    const QDir& getDir() const;
    QString getName() const;
    QStringList getPackages(const QString& strCategory) const;

private:
    QDir m_Dir;
};

#endif // REPOSITORY_HPP
