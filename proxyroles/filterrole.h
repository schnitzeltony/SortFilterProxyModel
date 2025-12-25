#ifndef FILTERROLE_H
#define FILTERROLE_H

#include "singlerole.h"
#include "filters/filtercontainer.h"

namespace SortFilterProxyModelQmlNamspace {

class FilterRole : public SingleRole, public FilterContainer
{
    Q_OBJECT
    Q_INTERFACES(SortFilterProxyModelQmlNamspace::FilterContainer)
    Q_PROPERTY(QQmlListProperty<SortFilterProxyModelQmlNamspace::Filter> filters READ filtersListProperty)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using SingleRole::SingleRole;

private:
    void onFilterAppended(Filter* filter) override;
    void onFilterRemoved(Filter* filter) override;
    void onFiltersCleared() override;

    QVariant data(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) override;
};

}

#endif // FILTERROLE_H
