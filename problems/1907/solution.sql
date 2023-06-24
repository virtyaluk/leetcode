# Write your MySQL query statement below
with income as (
    select
        case
            when income < 20000 then 'Low Salary'
            when income > 50000 then 'High Salary'
            else 'Average Salary'
        end as category,
        account_id
    from
        Accounts
), income_range as (
    select 'Low Salary' as category
    union
    select 'Average Salary' as category
    union
    select 'High Salary' as category
)

select
    a.category,
    count(account_id) as accounts_count
from
    income_range a
left join
    income b
on
    a.category = b.category
group by
    a.category