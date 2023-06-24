# Write your MySQL query statement below
select
    period_state,
    min(dates) as start_date,
    max(dates) as end_date
from (
    select
        period_state,
        dates,
        rn,
        row_number() over(order by dates) as rn2
    from (
        select
            success_date as dates,
            'succeeded' as period_state,
            row_number() over(order by success_date) as rn
        from
            Succeeded
        where
            year(success_date) = 2019
        union
        select
            fail_date as dates,
            'failed' as period_state,
            row_number() over(order by fail_date) as rn
        from
            Failed
        where
            year(fail_date) = 2019
    ) temp1
) temp2
group by
    period_state, rn2 - rn
order by
    start_date