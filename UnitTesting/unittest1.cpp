#include "stdafx.h"
#include "CppUnitTest.h"
#include "specializations.h"

// blocksolver headers
#include "../blocksolver/Point.h"
#include "../blocksolver/Piece.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestClassPoint)
		{
			// Test 2D points

			Point2D point2d1 = Point2D();
			Assert::AreEqual(point2d1[0], 0);
			Assert::AreEqual(point2d1[1], 0);

			Point2D point2d2 = Point2D(2, 3);
			Assert::AreEqual(point2d2[0], 2);
			Assert::AreEqual(point2d2[1], 3);

			Point2D point2d3 = point2d1;

			point2d1 += point2d2;
			Assert::AreEqual(point2d1, point2d2);

			point2d1 -= point2d2;
			Assert::AreEqual(point2d1, point2d3);

			point2d3 = point2d1 + point2d2;
			Assert::AreEqual(point2d3[0], 2);
			Assert::AreEqual(point2d3[1], 3);

			point2d1 = point2d3 - point2d1;
			Assert::AreEqual(point2d1, point2d2);


		    // inequality test

			Point2D point2d4 = Point2D(3, 4);
			Point2D point2d5 = Point2D(3, 3);
			Assert::AreNotEqual(point2d2, point2d4);
			Assert::AreNotEqual(point2d2, point2d5);
			Assert::AreNotEqual(point2d4, point2d5);



			// Test 3D points

			Point3D point3d1 = Point3D();

			Assert::IsTrue(point3d1[0] == 0);
			Assert::IsTrue(point3d1[1] == 0);

			Point3D point3d2 = Point3D(2, 3, 5);
			Assert::IsTrue(point3d2[0] == 2);
			Assert::IsTrue(point3d2[1] == 3);
			Assert::IsTrue(point3d2[2] == 5);

			Point3D point3d3 = point3d1;

			point3d1 += point3d2;
			Assert::AreEqual(point3d1, point3d2);

			point3d1 -= point3d2;
			Assert::AreEqual(point3d1, point3d3);

			point3d3 = point3d1 + point3d2;
			Assert::IsTrue(point3d3[0] == 2);
			Assert::IsTrue(point3d3[1] == 3);
			Assert::IsTrue(point3d3[2] == 5);

			point3d1 = point3d3 - point3d1;
			Assert::AreEqual(point3d1, point3d2);


		    // inequality test

			Point3D point3d4 = Point3D(3, 4, 6);
			Point3D point3d5 = Point3D(3, 3, 5);
			Point3D point3d6 = Point3D(2, 4, 5);
			Point3D point3d7 = Point3D(2, 3, 6);
			Assert::AreNotEqual(point3d2, point3d4);
			Assert::AreNotEqual(point3d2, point3d5);
			Assert::AreNotEqual(point3d2, point3d6);
			Assert::AreNotEqual(point3d2, point3d7);
			Assert::AreNotEqual(point3d4, point3d5);
			Assert::AreNotEqual(point3d4, point3d6);
			Assert::AreNotEqual(point3d4, point3d7);
		}

		TEST_METHOD(TestClassPiece)
		{
			// Test a 2D piece

			Point2D point2d1 = Point2D(0, 0);
			Point2D point2d2 = Point2D(1, 0);
			Point2D point2d3 = Point2D(1, 1);
			
			Piece2D piece2d1 = Piece2D();

			piece2d1.addPoint(point2d1);
			piece2d1.addPoint(point2d2);
			piece2d1.addPoint(point2d3);
			Assert::IsTrue(piece2d1.contains(Point2D(0, 0)));
			Assert::IsTrue(piece2d1.contains(Point2D(1, 0)));
			Assert::IsTrue(piece2d1.contains(Point2D(1, 1)));

			Piece2D piece2d2 = piece2d1.pieceFromAxisTransform(std::vector<bool>({ true, true }),
				std::vector<int>({ 1, 0 }));
			Assert::IsTrue(piece2d2.contains(Point2D(0, 0)));
			Assert::IsTrue(piece2d2.contains(Point2D(1, 0)));
			Assert::IsTrue(piece2d2.contains(Point2D(1, 1)));



			// Test a 3D piece

			Point3D point3d1 = Point3D(0, 0, 0);
			Point3D point3d2 = Point3D(1, 0, 0);
			Point3D point3d3 = Point3D(1, 1, 0);
			Point3D point3d4 = Point3D(1, 1, 1);

			Piece3D piece3d1 = Piece3D();

			piece3d1.addPoint(point3d1);
			piece3d1.addPoint(point3d2);
			piece3d1.addPoint(point3d3);
			piece3d1.addPoint(point3d4);
			Assert::IsTrue(piece3d1.contains(Point3D(0, 0, 0)));
			Assert::IsTrue(piece3d1.contains(Point3D(1, 0, 0)));
			Assert::IsTrue(piece3d1.contains(Point3D(1, 1, 0)));
			Assert::IsTrue(piece3d1.contains(Point3D(1, 1, 1)));

			Piece3D piece3d2 = piece3d1.pieceFromAxisTransform(std::vector<bool>({ true, true, true }),
				std::vector<int>({ 2, 1, 0 }));
			Assert::IsTrue(piece3d2.contains(Point3D(0, 0, 0)));
			Assert::IsTrue(piece3d2.contains(Point3D(1, 0, 0)));
			Assert::IsTrue(piece3d2.contains(Point3D(1, 1, 0)));
			Assert::IsTrue(piece3d2.contains(Point3D(1, 1, 1)));

		}
	};
}