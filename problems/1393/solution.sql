# Write your MySQL query statement below
WITH TABLE1 AS (
    SELECT *, CASE WHEN operation = 'Buy' THEN price * -1 ELSE price END AS 'gain_loss'
    FROM Stocks
)
SELECT stock_name, SUM(gain_loss) AS 'capital_gain_loss'
FROM TABLE1
GROUP BY stock_name
;