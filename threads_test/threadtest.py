from threads_api.threads_api import ThreadsApi

api = ThreadsApi('zuck') #, 'OPENAI-ORGANIZATION', 'OPENAI-API-KEY')

api.aiRequestType = 'osint.profile'  # osint.character_prompt || osint.profile || osint.links || osint.mentions

# api.gptModel = 'gpt-4'  # 'gpt-4' or 'gpt-3.5-turbo' recommended

api.maxPosts = 5  # max number of posts to scrape

api.pageLoadWaitTime = 60  # time to wait for page to load (change according to internet speed)

api.usingAI = False  # set to False to completely skip AI functionality

api.statusPrintingEnabled = True  # set to False to disable print statements from API


api.start()


# print(api.aiResponse)  # return AI request response

print(api.bio)  # return users bio

print(api.name)  # return users name

print(api.posts)  # return posts in array format

# print(api.links)  # return links, also includes mentions

# print(api.linkedInstagram)  # return linked instagram account url

# print(api.replies)  # return all replies

# print(api.replyLinks)  # return all links contained in replies

print(api.followers)  # return follower count