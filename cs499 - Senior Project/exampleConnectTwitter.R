#Loading the library
require(twitteR)

#Setting up the OAuth
consumer_key <- "AKxFaJPHG8i4DyZqkp98OH7Ua"
consumer_secret <- "2lZPp1S3yEdRt3VvfyaTjgCec03QLOFTpHBujFdImit2IxWRv4"
access_token<-"718577287570935808-ymw2pMC7d8wf6Pu25AjtlB6L2e5Lbgg"
access_secret<-"h1Z7Yv7H2Ew0H01nr1NHYgULrcQcnLVRzScVRR8eC6uh5"
setup_twitter_oauth(consumer_key, consumer_secret, access_token, access_secret)

#Get a specific user
user <- getUser("drrezeau")
show(user)
#this is just a method inside the data; use the $.
user$getFriends()

#getting recent tweets from a given acount
userTimeline("taylorswift13")
userTimeline("EmWatson")
#userTimeline("taylorswift13")

searchTwitter("pokemon", n=10, lang="en")