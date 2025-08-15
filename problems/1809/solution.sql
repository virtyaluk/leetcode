# Write your MySQL query statement below
select
    p.session_id
from
    Playback p
where
    p.session_id not in (
        select
            p2.session_id
        from
            Playback p2
        join
            Ads a
        on
            p2.customer_id = a.customer_id
        where
            a.timestamp between p2.start_time and p2.end_time
    )