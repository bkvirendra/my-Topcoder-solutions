from scrapy.spider import BaseSpider
from scrapy.contrib.spiders import CrawlSpider, Rule
from scrapy.contrib.linkextractors.sgml import SgmlLinkExtractor
from scrapy.selector import Selector
from scrapy.item import Item


class ZomatoSpider(CrawlSpider):
    name = "zomato"
    allowed_domains = ['zomato.com']
    start_urls = ['http://www.zomato.com/mumbai']

    rules = (
        Rule(
            SgmlLinkExtractor(allow=("/mumbai/restaurants"), deny=("?q=")),
            follow=True
        ),
        Rule(
            SgmlLinkExtractor(allow=("mumbai/restaurants/")),
            callback="rest_link_extractor"
        ),
    )

    def rest_link_extractor(self, response):
        self.log('Hi, this is an item page! %s' % response.url)
