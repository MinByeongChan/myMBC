update()와 save()는 document를 수정할 때 사용되는 메서드이다.

`update()`는 현재 존재하는 document 중 value를 수정할 때 사용된다.

그리고, `save()`는 현재 존재하는 document를 다른 document로 대체하게 된다. document내용을 부분적으로 수정하는 것이 아닌 통채로 변경한다는 의미이다.

# Update()

update 문법은 아래와 같다.

```
> db.COLLECTION_NAME.update(SELECTION_CRITERIA, UPDATED_DATA)
```

아래는 기존에 삽입된 movie 컬렉션에 있는 document를 하나 수정하는 예제이다.

```
> db.movie.update({"title":"The Avengers"}, {$set: {"title": "The Avengers New"}})
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })
```

title이 The Avengers인 document를 Avengers New라고 update한 결과이다.

변경된 document 내용을 확인하고 싶다면 find()로 확인할 수 있다.

```
> db.movie.find().pretty()
{
        "_id" : ObjectId("6044aacb51e8c7ef25cc0e15"),
        "title" : "The Avengers New",
        "director" : "Joss Whedon",
        "country" : "United States",
        "release_date" : ISODate("2012-05-11T07:00:00Z")
}
```

하지만, 위의 예제는 title이 The Avengers에 매칭되는 document만 수정이된다. 다시말해, 하나만 수정된다. 예를 들어 age가 23에 해당하는 document 여러개를 수정하고 싶은 경우엔 위와같은 명령어는 사용하기 난해하다.

이런 경우를 대비하기 위해 `multi` 라는 키워드가 있다.

```
> db.movie.update({"age":23}, {$set: {"description": "바보"}}, {multi: true})
```

`{multi: true}`옵션은 추가하면 age: 23에 해당하는 여러개의 document가 수정된다.

# save()

앞서 언급한 바와같이 save()는 기존의 document를 새로운 document로 대체할 때 사용되는 메서드이다. document가 부분적으로 수정하는 것이 아닌, 통채로 수정된다.

```
> db.COLLECTION_NAME.save({_id:ObjectId(),NEW_DATA})
```

`_id`를 찾아서 새로운 document로 대체하는 방식으로 update가 진행된다.

```
> db.movie.save({
        "_id" : ObjectId("603df6cd7ba23d5d2c809d4f"),
        "title" : "Hello",
        "director" : "Taika Waititi",
        "country" : "Korea",
        "release_date" : new Date("2021","02","07")
})
WriteResult({ "nMatched" : 1, "nUpserted" : 0, "nModified" : 1 })
```

수정하고 싶은 해당 `_id`를 입력하고 document에 추가 또는 수정하고싶은 key와 value를 입력하면 된다.

find()메서드로 출력결과를 확인해보면 다음과 같이 나온다.

```
> db.movie.find().pretty()
{
        "_id" : ObjectId("603df6cd7ba23d5d2c809d4f"),
        "title" : "Hello",
        "director" : "Taika Waititi",
        "country" : "Korea",
        "release_date" : ISODate("2021-03-07T07:00:00Z")
}
```

정상적으로 추가되는것을 확인할 수 있다.

# findOneAndUpdate()

multi키워드를 사용하지 않았을때의 update()와 비슷한 맥락이다. 차이점이 있다면 출력결과가 다르게 나온다. 아래 예제를 참고하자.

```
> db.movie.findOneAndUpdate({"title": "Hello"}, {$set: { director: "MBC" }} )
{
        "_id" : ObjectId("603df6cd7ba23d5d2c809d4f"),
        "title" : "Hello",
        "director" : "Taika Waititi",
        "country" : "Korea",
        "release_date" : ISODate("2021-03-07T07:00:00Z")
}
```

find()를 사용할때와 별반 다르지 않다. title이 "Hello"인 document를 `하나만` 찾고, 수정하고 싶은 document를 작성한다.

하지만, 수정하고 결과가 어떻게 변경되었는지 JSON 형태로 직관적으로 보여주는 차이점이 있다.
