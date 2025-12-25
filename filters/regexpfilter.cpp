#include "regexpfilter.h"
#include <QVariant>

namespace SortFilterProxyModelQmlNamspace {

/*!
    \qmltype RegExpFilter
    \inherits RoleFilter
    \inqmlmodule SortFilterProxyModel
    \ingroup Filters
    \brief  Filters rows matching a regular expression.

    A RegExpFilter is a \l RoleFilter that accepts rows matching a regular rexpression.

    In the following example, only rows with their \c lastName role beggining with the content of textfield the will be accepted:
    \code
    TextField {
       id: nameTextField
    }

    SortFilterProxyModel {
       sourceModel: contactModel
       filters: RegExpFilter {
           roleName: "lastName"
           pattern: "^" + nameTextField.displayText
       }
    }
    \endcode
*/

/*!
    \qmlproperty bool RegExpFilter::pattern

    The pattern used to filter the contents of the source model.

    \sa syntax
*/
QString RegExpFilter::pattern() const
{
    return m_pattern;
}

void RegExpFilter::setPattern(const QString& pattern)
{
    if (m_pattern == pattern)
        return;

    m_pattern = pattern;
    m_regExp.setPattern(pattern);
    Q_EMIT patternChanged();
    invalidate();
}

/*!
    \qmlproperty Qt::CaseSensitivity RegExpFilter::caseSensitivity

    This property holds the caseSensitivity of the filter.
*/
Qt::CaseSensitivity RegExpFilter::caseSensitivity() const
{
    return m_caseSensitivity;
}

void RegExpFilter::setCaseSensitivity(Qt::CaseSensitivity caseSensitivity)
{
    if (m_caseSensitivity == caseSensitivity)
        return;

    m_caseSensitivity = caseSensitivity;
    m_regExp.setCaseSensitivity(caseSensitivity);
    Q_EMIT caseSensitivityChanged();
    invalidate();
}

bool RegExpFilter::filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const
{
    QString string = sourceData(sourceIndex, proxyModel).toString();
    return m_regExp.indexIn(string) != -1;
}

}
