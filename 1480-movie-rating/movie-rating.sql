-- # Write your MySQL query statement below
select name as results from 
(select u.name 
from users u join movierating m
 on u.user_id = m.user_id
  group by u.user_id order by count(*) desc, u.name asc limit 1) as topuser

union all

select title as resutls from
(
select m.title
from movies m
join movierating r on m.movie_id = r.movie_id
where month(r.created_at) =2  AND YEAR(r.created_at) = 2020
group by m.movie_id
order by avg(r.rating) desc, m.title asc limit 1) as topmovie

