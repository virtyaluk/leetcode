# Write your MySQL query statement below
select
    distinct user_id
from
    Loans
group by
    user_id
having
    sum(loan_type = 'Mortgage') > 0
    and
    sum(loan_type = 'Refinance') > 0
order by
    1