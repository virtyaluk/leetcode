delete from Person where id in (
    select id from (
        select t.*, dense_rank() over(
            partition by email order by id
        ) as rn from Person t
    ) x where x.rn > 1
)