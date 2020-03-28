package com.example.demo.mapper;


import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.stereotype.Repository;

import com.example.demo.model.BoardData;

@Repository("com.example.demo.mapper.BoardMapper")
public interface BoardMapper {

	public List<BoardData> selectAllBoard() throws Exception;
	
	public void selectAllBoard(Map<String, String> map) throws Exception;
	
	public int insert(BoardData boardData) throws Exception;
}
