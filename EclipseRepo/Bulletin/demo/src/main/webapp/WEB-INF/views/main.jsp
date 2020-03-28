<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>MBC's 게시판</title>
<link rel="stylesheet" type="text/css"
	href="/coco/resources/semantic.min.css">

<style type="text/css">
body {
	background-color: #DADADA;
}

.view_btn {
	cursor: pointer;
}
</style>
</head>
<body>
	<div class="ui middle aligned center aligned grid">
		<div class="column">
			<h2 class="ui teal image header">게시판 페이지</h2>
			<div class="ui large form">
				<div class="ui stacked segment">
					<button
							class="ui fluid large teal submit button">게시글 작성하기</button>
					<table class="ui celled table">
						<thead>
							<tr>
								<th>#</th>
								<th>제목</th>
								<th>등록자</th>
								<th>등록일</th>
							</tr>
						</thead>
						<tbody id="list">
						</tbody>
					</table>
				</div>

				<div class="ui error message"></div>

			</div>
		</div>
	</div>

	<div class="ui modal" id='view_modal'>
		<i class="close">x</i>
		<div class="header" id="b_title"></div>
		<div class="content">
			<div class="description">
				<p style="text-align: right" id="b_review"></p>
				<div id='b_content'></div>
			</div>
		</div>
		<div class="actions">
			<div class="ui black deny button">닫기</div>
		</div>
	</div>
	
	<!-- js 가져오기 -->
    <script src="/coco/resources/jquery3.3.1.min.js"></script>
    <script src="/coco/resources/semantic.min.js"></script>
 
    <script type="text/javascript">
    	$(document).ready(function() {
    		$.ajax({
    			type:"get",
    			url:"/index2",
    			success:function(data) {
    				
    			},
    			error:function(error) {
    				alert("오류발생");
    			}
    		});
    	})
    
    </script>



</body>
</html>