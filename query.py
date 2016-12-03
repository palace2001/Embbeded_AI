#!/usr/bin/env python

import wolframalpha
import os
import sys

app_id='QW8J45-V6Y3X7HTHX'

client = wolframalpha.Client(app_id)

query = ' '.join(sys.argv[1:])
res = client.query(query)


if res['@success'] == "true":
	print next(res.results).text.encode('utf-8')
else:
	print "Sorry, I am not sure."
