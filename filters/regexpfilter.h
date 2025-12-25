#ifndef REGEXPFILTER_H
#define REGEXPFILTER_H

#include "rolefilter.h"
#include <QRegExp>

namespace SortFilterProxyModelQmlNamspace {

class RegExpFilter : public RoleFilter {
    Q_OBJECT
    Q_PROPERTY(QString pattern READ pattern WRITE setPattern NOTIFY patternChanged)
    Q_PROPERTY(Qt::CaseSensitivity caseSensitivity READ caseSensitivity WRITE setCaseSensitivity NOTIFY caseSensitivityChanged)

public:
    using RoleFilter::RoleFilter;

    QString pattern() const;
    void setPattern(const QString& pattern);

    Qt::CaseSensitivity caseSensitivity() const;
    void setCaseSensitivity(Qt::CaseSensitivity caseSensitivity);

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void patternChanged();
    void syntaxChanged();
    void caseSensitivityChanged();

private:
    QRegExp m_regExp;
    Qt::CaseSensitivity m_caseSensitivity = m_regExp.caseSensitivity();
    QString m_pattern = m_regExp.pattern();
};

}

#endif // REGEXPFILTER_H
