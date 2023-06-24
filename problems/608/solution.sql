# Write your MySQL query statement below
select
    id,
    if(isnull(p_id), 'Root', if(id in (select p_id from Tree), 'Inner', 'Leaf')) as type
from
    Tree
order by
    id asc