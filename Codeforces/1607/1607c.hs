import Prelude
import Data.List

test :: Int -> IO ()
test 0 = putStrLn ""
test t = do
    nn <- getLine
    let n = (read nn :: Int)
    aa <- getLine
    let arr = sort (map (\x -> read x :: Int) (words aa))
    let ans = solve arr 0 (head arr)
    putStrLn (show ans)
    test (t - 1)


solve :: [Int] -> Int -> Int -> Int
solve [] _ cur = cur
solve (x : xs) sub cur = 
    let new = x - sub
    in solve xs (sub + new) (max cur new)

main :: IO ()
main = do
    tt <- getLine
    let t = (read tt :: Int)
    test t