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