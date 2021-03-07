const fetchData = () => {
  return (data = fetch("https://api.thecatapi.com/v1/breeds").then((res) => {
    return res.json();
  }));
};

async function getData() {
  const arr = await fetchData();
  document.querySelector(".loading").style.opacity = "0";

  for (let i = 0; i < 30; i++) {
    let article = document.createElement("article");
    article.className = "card";

    article.innerHTML = `
        <h1>${arr[i].name}</h1>
        <img class="cat_img" data-id="cat_img1" src="${arr[i].image.url}"/>
        <p>${arr[i].origin}</p>
        <p>${arr[i].temperament}</p>
        
    `;
    document.querySelector(".card-wrapper").append(article);
  }

  return callback(arr);
}

const callback = (arr) => {
  console.log("arr", arr);
};

getData();
