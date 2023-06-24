# Write your MySQL query statement below
select
    *
from
    Users
where
    lower(mail) regexp '^[a-z]+[a-z0-9_.-]*@leetcode\\.com'