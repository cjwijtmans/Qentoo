#ifndef REPOSITORY_HPP
#define REPOSITORY_HPP

#include <QDir>
#include <QString>
#include <QStringList>

class Repository
{
public:
    explicit Repository(const QDir& dir);
    QStringList getCategories() const;
    const QDir& getDir() const;
    QString getName() const;
    QStringList getPackages(const QString& strCategory) const;

private:
    QDir m_Dir;
};

#endif // REPOSITORY_HPP
