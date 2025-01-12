/* Write your PL/SQL query statement below */
WITH CTE AS (
  SELECT
    content_id,
    content_text,
    REGEXP_SUBSTR( new_text, '[^ ]+', 1, LEVEL ) converted_single_text 
  FROM
    ( SELECT content_id, content_text, REPLACE ( content_text, '-', ' -' ) new_text FROM user_content ) sub 
  CONNECT BY REGEXP_SUBSTR( new_text, '[^ ]+', 1, LEVEL ) IS NOT NULL 
    AND PRIOR content_id = content_id 
    AND PRIOR SYS_GUID ( ) IS NOT NULL 
),
CTE2 AS (
  SELECT
    content_id,
    content_text,
    DECODE( is_s, 1, '-' || converted_single_text2, converted_single_text2 ) AS converted_single_text3,
    ROW_NUMBER ( ) OVER ( ORDER BY ( NULL ) ) keyid 
  FROM
    (
    SELECT
      content_id,
      content_text,
      is_s,
      UPPER( SUBSTR( converted_single_text, 1, 1 ) ) || LOWER( SUBSTR( converted_single_text, 2, LENGTH( converted_single_text ) ) ) converted_single_text2 
    FROM
      (
      SELECT
        content_id,
        content_text,
        REPLACE ( converted_single_text, '-', '' ) converted_single_text,
      CASE
          
          WHEN converted_single_text LIKE '%-%' THEN
          1 ELSE 0 
        END is_s 
FROM
  CTE 
  ) sub 
  ) sub1 
)
SELECT
  content_id AS "content_id",
  content_text AS "original_text",
  REPLACE ( LISTAGG ( converted_single_text3, ' ' ) WITHIN GROUP ( ORDER BY keyid ), ' -', '-' ) AS "converted_text" 
FROM
  CTE2 
GROUP BY
  content_id,
  content_text 
ORDER BY
  content_id;
