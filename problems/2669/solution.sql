# Write your MySQL query statement below
select
    artist,
    count(*) as occurrences
from
    Spotify
group by
    artist
order by
    2 desc,
    1 asc