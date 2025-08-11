# Write your MySQL query statement below
select employee_id from employees e where e.employee_id not in ( select employee_id from salaries)
union
select employee_id from salaries s where s.employee_id not in ( select employee_id from employees)
order by employee_id asc;
