<div itemscope itemtype="http://schema.org/ProfessionalService">
  <span itemprop="name">[company:services:primary:name]</span>
  <div itemprop="aggregateRating" itemscope itemtype="http://schema.org/AggregateRating">
      <span itemprop="ratingValue">[company:rating:value]</span>
      out of <span itemprop="bestRating">[company:rating:total]</span>
      based on <span itemprop="reviewCount">[company:reviews:total]</span> user ratings
  </div>
</div>

<div class="row" itemscope itemtype="http://schema.org/Review">
  <p itemprop="reviewBody">[company:reviews:[]:body]</p>
  <small itemprop="author" itemscope itemtype="http://schema.org/Person"><a href="http://calgaryroofingdoneright.com/" target="_blank" itemprop="url"><span itemprop="name">[company:reviews:[]:author:name]</span></a></small>
  
  <div itemprop="itemReviewed" itemscope itemtype="http://schema.org/ProfessionalService">
    <span itemprop="name">[company:services:primary:name]</span>
  </div>
  
  <div itemprop="reviewRating" itemscope itemtype="http://schema.org/Rating">
    <meta itemprop="worstRating" content="1"><span itemprop="ratingValue">[company:reviews:[]:rating:value]</span> / <span itemprop="bestRating">[company:reviews:[]:rating:total]</span> stars
  </div>
</div>
