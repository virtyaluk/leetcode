SELECT CANDIDATE_ID FROM CANDIDATES WHERE
YEARS_OF_EXP >= 2
AND INTERVIEW_ID IN
(SELECT INTERVIEW_ID FROM ROUNDS
GROUP BY INTERVIEW_ID HAVING SUM(SCORE) > 15);