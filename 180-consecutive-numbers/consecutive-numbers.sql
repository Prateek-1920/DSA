# Write your MySQL query statement below
select distinct num  as ConsecutiveNums from 
(
select num, 
lead(num,1) over(order by id asc) as next1,
lead(num,2) over(order by id asc) as next2
from logs
)t
where num = next1 and num = next2;
