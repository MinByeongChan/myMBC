package com.example.demo.controller;

import javax.annotation.Resource;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.example.demo.model.BoardData;
import com.example.demo.model.Criteria;
import com.example.demo.model.PageMaker;
import com.example.demo.service.BoardService;

@CrossOrigin
@Controller
public class BoardController {

	@Resource
	BoardService service;
	
	@RequestMapping(value = "/teset2")
	public String test2() {
		return "/index";
	}

	@RequestMapping(value = "/main")
	public String index() {
		return "main";
	}

	private static final Logger logger = LoggerFactory.getLogger(BoardController.class);


	// 게시판 글 작성 화면
	@RequestMapping(value="/writeView", method=RequestMethod.GET)
	public String createView(BoardData boardData) throws Exception {
		logger.info("createView");

		if(boardData.getSubject() != null) {
			service.create(boardData);
		}
		
		return "/writeView";
	}

	// 게시판 글 작성
	@RequestMapping(value = "/write", method = RequestMethod.POST)
	public String write(BoardData boardData) throws Exception {
		logger.info("write");

		service.write(boardData);

		System.out.println("boardData : " + boardData);

		return "redirect:/list";
	}

//	@RequestMapping(value = "/list", method = RequestMethod.GET)
//	public String list(Model model) throws Exception {
//		logger.info("list");
//
//		model.addAttribute("list", service.list());
//
//		return "/list";
//	}

	@RequestMapping(value="/readView", method=RequestMethod.GET)
	public String read(BoardData boardData, Model model) throws Exception {
		
		logger.info("read");

		model.addAttribute("read", service.read(boardData.getIdx()));

		return "/readView";
	}
	
	@RequestMapping(value="/updateView", method=RequestMethod.GET)
	public String updateView(BoardData boardData, Model model) throws Exception {
		logger.info("updateView");

		model.addAttribute("update", service.read(boardData.getIdx()));

		return "/updateView";
	}

	@RequestMapping(value = "/update", method = RequestMethod.POST)
	public String update(BoardData boardData) throws Exception {

		logger.info("update");

		service.update(boardData);

		return "redirect:/list";
	}

	@RequestMapping(value = "/delete", method = RequestMethod.POST)
	public String delete(BoardData boardData) throws Exception {
		logger.info("delete");

		service.delete(boardData.getIdx());

		return "redirect:/list";
	}

	@RequestMapping(value="/list", method = RequestMethod.GET)
	public String list(Model model, Criteria cri) throws Exception{
		logger.info("list");
		
		model.addAttribute("list", service.list(cri));
		
		PageMaker pageMaker = new PageMaker();
		pageMaker.setCri(cri);
		pageMaker.setTotalCount(service.listCount());
		
		model.addAttribute("pageMaker", pageMaker);
		
		return "/list";
	}
	
}