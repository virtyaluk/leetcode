select
    a.symbol as metal,
    b.symbol as nonmetal
from
    Elements a,
    Elements b
where
    a.type = 'Metal' and b.type = 'Nonmetal'