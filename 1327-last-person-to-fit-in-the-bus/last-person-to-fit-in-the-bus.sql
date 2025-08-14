# Write your MySQL query statement below
with temp as 
(
    select *,
    sum(weight) over(order by turn) as running_sum
    from queue
)

select person_name from temp where running_sum<=1000
order by running_sum desc limit 1;