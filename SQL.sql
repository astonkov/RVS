call RVS.addNumber(1);
SELECT * FROM RVS.numbers;
TRUNCATE RVS.numbers;
create database RVS;
drop table RVS.numbers;
create table RVS.numbers (numbers bigint);

drop PROCEDURE addNumber;
DELIMITER $$
CREATE PROCEDURE RVS.`addNumber`(
IN number_input bigint
)
BEGIN
if ( select exists (select 1 from RVS.numbers where numbers = number_input) ) THEN

select 'Number exitsts !!';

ELSE

if ( select exists (select 1 from RVS.numbers where numbers = (number_input + 1)) ) THEN

select 'Number is less by 1 then exitsting !!';

ELSE

insert into RVS.numbers
(
numbers
)
values
(
number_input
);

select number_input + 1 as val;

END IF;
END IF;
END$$
DELIMITER ;