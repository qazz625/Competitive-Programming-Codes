import Prelude

test :: Int -> IO ()
test 0 = putStrLn ""
test n = do
    alphabets <- getLine
    s <- getLine
    let first  = findIndex alphabets (head s) 0
    let ans = solve alphabets s first
    print ans
    test (n - 1)

main :: IO ()
main = do
    tt <- getLine
    let t = (read tt :: Int)
    test t

solve :: String -> String -> Int -> Int
solve alphabets "" prev = 0
solve alphabets (x : xs) prev =
    let ind = findIndex alphabets x 0
    in abs (ind - prev) + solve alphabets xs ind

findIndex :: String -> Char -> Int -> Int
findIndex "" _ n = -1
findIndex (a : as) x n =
    if x == a
        then n
        else findIndex as x (n + 1)