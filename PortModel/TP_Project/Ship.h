#pragma once
#define _USE_MATH_DEFINES


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Resources;
using namespace System::Collections::Generic;

#include <iostream>
#include <cmath>
#include "Resource.h"
#include <ctime>


ref class Turning {
public:
	bool TurningWasSelected = 0;
	bool RightTurning = 1;
};

ref class Vector2
{
public:
	// Конструкторы класса
	Vector2()
	{	
		angle_ = 0;
		x = 1;
		y = 0;
	}

	Vector2(double alpha)
	{
		alpha = alpha * M_PI / 180.0;
		x = cos(alpha);
		y = sin(alpha);
	}

	property double angle {
		void set(double a) {
			if (a > 360) angle_ = fmod(a,360);
			else
			{
				angle_ = a;
			}
			if (angle_ < 0) angle_ += 360;
			x = cos(angle_ * M_PI / 180.0);
			y = sin(angle_ * M_PI / 180.0);
		}
		double get() {
			return angle_;
		}
	}

	property double X {
		double get() {
			return x;
		}
	}
	property double Y {
		double get() {
			return y;
		}
	}

private:
	double angle_;
	double x;
	double y;
};


public delegate void FinishPathHandler(Object^ sender);


ref class Path {
private:
	array<Point>^ checkpoints;
	int currentCheckpointIndex;

public:
	static array<Path^>^ All_Paths;
	FinishPathHandler^ PathEnded;

	Path(array<Point>^ _checkpoints) {
		checkpoints = _checkpoints;
		currentCheckpointIndex = 0;
	}
	Path(array<Point>^ _checkpoints, FinishPathHandler^ finishHandler) : Path(_checkpoints){
		PathEnded = finishHandler;
	}
	Path(int i) {
		checkpoints = All_Paths[i]->checkpoints;
		PathEnded = All_Paths[i]->PathEnded;
		currentCheckpointIndex = 0;
	}
	void AddPoint(int x, int y) {
		// Создаем новый массив точек, увеличивая его размер на 1
		array<Point>^ newCheckpoints = gcnew array<Point>(checkpoints->Length + 1);

		// Копируем существующие точки в новый массив
		for (int i = 0; i < checkpoints->Length; i++) {
			newCheckpoints[i] = checkpoints[i];
		}

		// Добавляем новую точку в конец массива
		newCheckpoints[checkpoints->Length] = Point(x, y);

		// Обновляем массив точек
		checkpoints = newCheckpoints;
	}


	Point getNextCheckpoint() {
		if (currentCheckpointIndex < checkpoints->Length) {
			Point nextCheckpoint = checkpoints[currentCheckpointIndex];
			return nextCheckpoint;
		}
		else {
			return Point(-1, -1); // возвращаем точку с недопустимыми координатами, если достигли конца пути
		}
	}

	double calculateDirection(Point currentLocation) {
		Point nextCheckpoint = getNextCheckpoint();
		if (nextCheckpoint.X == -1 && nextCheckpoint.Y == -1) {
			// если достигли конца пути, вернем значение по умолчанию
			return 0.0;
		}
		else {
			double dx = nextCheckpoint.X - currentLocation.X;
			double dy = nextCheckpoint.Y - currentLocation.Y;
			double angle = atan2(dy, dx) * 180.0 / M_PI;
			if (angle < 0) angle = 360 + angle;
			return angle;
		}
	}

	//Метод вычисления расстояния до точки
	double distanceCalc(Point loc) {
		int x = checkpoints[currentCheckpointIndex].X;
		int y = checkpoints[currentCheckpointIndex].Y;
		double d = sqrt((x - loc.X) * (x - loc.X) + (y - loc.Y) * (y - loc.Y));
		return d;
	}

	//Метод проверки достижения чекпоинта
	bool CheckValidate(Point loc, int tecMovementSpeed) {
		if (currentCheckpointIndex <= checkpoints->Length - 1) {
			int minX = checkpoints[currentCheckpointIndex].X - tecMovementSpeed / 2;
			int maxX = checkpoints[currentCheckpointIndex].X + tecMovementSpeed / 2;
			int minY = checkpoints[currentCheckpointIndex].Y - tecMovementSpeed / 2;
			int maxY = checkpoints[currentCheckpointIndex].Y + tecMovementSpeed / 2;

			// Проверяем, находится ли текущая позиция в области вокруг целевого чекпоинта
			if (loc.X >= minX && loc.X <= maxX && loc.Y >= minY && loc.Y <= maxY) {
				currentCheckpointIndex++;
				return true;
			}
		}
		return false;
	}

	//Метод проверки достижения финальной точки
	bool CheckFinal() {
		if (currentCheckpointIndex >= checkpoints->Length) {
			return true;
		}
		return false;
	}
	
	double CalcAngleBetweenTwoLastPoint() {
		double dx = checkpoints[currentCheckpointIndex - 1].X - checkpoints[currentCheckpointIndex - 2].X;
		double dy = checkpoints[currentCheckpointIndex - 1].Y - checkpoints[currentCheckpointIndex - 2].Y;
		double angle = atan2(dy, dx) * 180.0 / M_PI;
		if (angle < 0) angle = 360 + angle;
		return angle;
	}
};

ref class HitBox {
public:
	//Массив точек хитбокса
	array<PointF>^ points = gcnew array<PointF>(4);
	array<PointF>^ startPoints = gcnew array<PointF>(4);

	array<Point>^ RedZone = gcnew array<Point>(4);
	array<Point>^ YellowZone = gcnew array<Point>(4);
	array<Point>^ GreenZone = gcnew array<Point>(4);
	
	
	HitBox(Image^ ImageShip) {
		// Вычисляем новые координаты углов изображения
		points[0] = System::Drawing::PointF(-ImageShip->Width / 2.0, -ImageShip->Height / 2.0);
		points[1] = System::Drawing::PointF(ImageShip->Width / 2.0, -ImageShip->Height / 2.0);
		points[2] = System::Drawing::PointF(ImageShip->Width / 2.0, ImageShip->Height / 2.0);
		points[3] = System::Drawing::PointF(-ImageShip->Width / 2.0, ImageShip->Height / 2.0);
		
		startPoints = points;
	}

	property PointF TopLeft {
		PointF get() {
			return points[0];
		}
	}
	property PointF TopRight {
		PointF get() {
			return points[1];
		}
	}
	property PointF BotRight {
		PointF get() {
			return points[2];
		}
	}
	property PointF BotLeft {
		PointF get() {
			return points[3];
		}
	}

	//Применение поворота на угол
	void RotatePoints(double angle, Image^ ImageShip) {
		array<PointF>^ copyStartPoints = gcnew array<PointF>(4);
		copyStartPoints[0] = System::Drawing::PointF(-ImageShip->Width / 2.0, -ImageShip->Height / 2.0);
		copyStartPoints[1] = System::Drawing::PointF(ImageShip->Width / 2.0, -ImageShip->Height / 2.0);
		copyStartPoints[2] = System::Drawing::PointF(ImageShip->Width / 2.0, ImageShip->Height / 2.0);
		copyStartPoints[3] = System::Drawing::PointF(-ImageShip->Width / 2.0, ImageShip->Height / 2.0);

		// Создаем матрицу трансформации для поворота
		System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
		matrix->RotateAt(angle, System::Drawing::PointF(0,0));

		tecAngle = angle;
		// Применяем матрицу трансформации к точкам
		matrix->TransformPoints(copyStartPoints);
						
		points = copyStartPoints;
	}
	
	int YZ_min_chislo = 10;
	int YZ_max_chislo = 20;

	int GZ_min_chislo = 20;
	int GZ_max_chislo = 50;

	void EditZones(Point center) {
		//Делаем красную зону (абсолютные координаты точек)
		RedZone[0] = Point(points[0].X + center.X, points[0].Y + center.Y);
		RedZone[1] = Point(points[1].X + center.X, points[1].Y + center.Y);
		RedZone[2] = Point(points[2].X + center.X, points[2].Y + center.Y);
		RedZone[3] = Point(points[3].X + center.X, points[3].Y + center.Y);

		//Немного расширяем зону и формируем ЖЗ
		YellowZone[0] = Point(startPoints[0].X - YZ_min_chislo + center.X, startPoints[0].Y - YZ_min_chislo + center.Y);
		YellowZone[1] = Point(startPoints[1].X + YZ_max_chislo + center.X, startPoints[1].Y - YZ_min_chislo + center.Y);
		YellowZone[2] = Point(startPoints[2].X + YZ_max_chislo + center.X, startPoints[2].Y + YZ_min_chislo + center.Y);
		YellowZone[3] = Point(startPoints[3].X - YZ_min_chislo + center.X, startPoints[3].Y + YZ_min_chislo + center.Y);

		//Немного расширяем зону и формируем ЗЗ
		GreenZone[0] = Point(startPoints[0].X - GZ_min_chislo + center.X, startPoints[0].Y - GZ_min_chislo + center.Y);
		GreenZone[1] = Point(startPoints[1].X + GZ_max_chislo + center.X, startPoints[1].Y - GZ_min_chislo + center.Y);
		GreenZone[2] = Point(startPoints[2].X + GZ_max_chislo + center.X, startPoints[2].Y + GZ_min_chislo + center.Y);
		GreenZone[3] = Point(startPoints[3].X - GZ_min_chislo + center.X, startPoints[3].Y + GZ_min_chislo + center.Y);
		
		// Создаем матрицу трансформации для поворота
		System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
		matrix->RotateAt(tecAngle, center);

		// Применяем матрицу трансформации к точкам
		matrix->TransformPoints(GreenZone);
		matrix->TransformPoints(YellowZone);
	}

	bool CheckIntersecting(array<Point>^ area1, array<Point>^ area2)
	{
		for (int i = 0; i < 4; ++i) {
			Point p1 = area1[i];
			Point p2 = area1[(i + 1) % 4];

			for (int j = 0; j < 4; ++j) {
				Point p3 = area2[j];
				Point p4 = area2[(j + 1) % 4];

				if (segmentsIntersect(p1, p2, p3, p4)) {
					return true;
				}
			}
		}
		return false;
	}

	bool segmentsIntersect(Point p1, Point p2, Point p3, Point p4) {
		double det = (p2.X - p1.X) * (p4.Y - p3.Y) - (p4.X - p3.X) * (p2.Y - p1.Y);
		if (det == 0) // отрезки параллельны
			return false;

		double lambda = ((p4.Y - p3.Y) * (p4.X - p1.X) + (p3.X - p4.X) * (p4.Y - p1.Y)) / det;
		double gamma = ((p1.Y - p2.Y) * (p4.X - p1.X) + (p2.X - p1.X) * (p4.Y - p1.Y)) / det;

		return (0 < lambda && lambda < 1) && (0 < gamma && gamma < 1);
	}
private: 
	double tecAngle = 0;
};


public delegate void PictureBoxPaintHandler(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

ref class Transport {
public:
	static Windows::Forms::Form^ frm;
	static PictureBoxPaintHandler^ handler;
	
	event FinishPathHandler^ TransportIsFinished;

	protected: int Transport_ID_;
	public:	
	property int Transport_ID {
		int get() {
			return Transport_ID_;
		}
	}
	static array<PictureBox^>^ All_PictureBox;
	
	virtual array<Transport^>^ All_Transport(){
		return nullptr;
	}

	//Конструктор класса
	Transport() {
		pictureBox = gcnew PictureBox();
		pictureBox->SizeMode = PictureBoxSizeMode::CenterImage; // Масштабирование изображения, чтобы оно заполняло PictureBox
		pictureBox->BackColor = Color::Transparent;
		direction = gcnew Vector2();
		turningDirection = gcnew Turning();
	}


	Transport(Point loc) :Transport() {
		Array::Resize(All_PictureBox, All_PictureBox->Length + 1);
		All_PictureBox[All_PictureBox->Length - 1] = pictureBox;
		print(loc, frm);
		pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(handler, &PictureBoxPaintHandler::Invoke);
	}
	~Transport() {
		frm->Controls->Remove(pictureBox);
		delete pictureBox;
		delete CurrentPath;
	}

	//Метод размещения коробля
	void print(Point loc, System::Windows::Forms::Form^ frm) {
		pictureBox->Location = Point(loc.X - pictureBox->Width / 2, loc.Y - pictureBox->Height / 2);
		frm->Controls->Add(pictureBox);
	}

	//Вектор направления
	Vector2^ direction;

	//ЦентрИзображения
	Point CurrentLocation() {
		return Point(pictureBox->Location.X + pictureBox->Width / 2, pictureBox->Location.Y + pictureBox->Height / 2);
	}

	
	void DeletePictureBox() {
		List<PictureBox^>^ newAll_PictureBox = gcnew List<PictureBox^>(All_PictureBox);
		newAll_PictureBox->Remove(pictureBox);
		All_PictureBox = newAll_PictureBox->ToArray();
	}

	//Метод перемещения
	void moving() {
		tecMovementSpeed = maxMovementSpeed;
		if (maxMovementSpeed != -1) {
			//Сначала высчитывает направление к чекпоинту
			double newAngle = CurrentPath->calculateDirection(CurrentLocation());

			//Если очень близко и сзади то врубим задний ход исключительно для этого чекпоинта
			if (CurrentPath->distanceCalc(CurrentLocation()) <= 300 && reverseGear != 1 && turningDirection->TurningWasSelected != 1 && (abs(newAngle - direction->angle) >= 120 && abs(newAngle - direction->angle) <= 240)) {
				reverseGear = 1;
				maxMovementSpeed = ABS_maxMovementSpeed_ / 2;
				tecMovementSpeed = -1;
				direction->angle += 180;
			}
			bool CheckRotating = CheckRotate(direction->angle);
			if (CheckRotating) {

				//Решить в какую сторону мы будем вращать корабль 
				int diff1 = (int)(newAngle - direction->angle + 360) % 360;
				int diff2 = (int)(direction->angle - newAngle + 360) % 360;

				if (!turningDirection->TurningWasSelected) {
					if (diff1 < diff2) {
						if (abs(newAngle - direction->angle) <= angularSpeed) direction->angle = newAngle;
						else direction->angle += angularSpeed;
						turningDirection->RightTurning = 1;
					}
					else if (diff2 < diff1) {
						if (abs(newAngle - direction->angle) <= angularSpeed) direction->angle = newAngle;
						else direction->angle -= angularSpeed;
						turningDirection->RightTurning = 0;
					}
					else {
						direction->angle = newAngle;
					}
					turningDirection->TurningWasSelected = 1;
				}
				else {
					if (abs(newAngle - direction->angle) <= angularSpeed) {
						direction->angle = newAngle;
					}
					else if (turningDirection->RightTurning) direction->angle += angularSpeed;
					else if (!turningDirection->RightTurning) direction->angle -= angularSpeed;
				}

				if (CheckLastAngle && ((abs(lastAngle - newAngle) > 1 && CurrentPath->distanceCalc(CurrentLocation()) > 100) || abs(lastAngle - newAngle) > angleSpread)) {	//Поворачивается
					reverseGear ? RotatePictureBox(direction->angle + 180) : RotatePictureBox(direction->angle);
					lastAngle = direction->angle;
				}
				if (newAngle == lastAngle) CheckLastAngle = 0;

			}
			hitBox->EditZones(CurrentLocation());
			//Проверка столкновения
			CheckCollisions();
			pictureBox->Invalidate();
			if (!(reverseGear == 1 && !CheckRotating && direction->angle != newAngle)) {
				//Движется
				pictureBox->Location = Point(pictureBox->Location.X + (int)(tecMovementSpeed * direction->X), pictureBox->Location.Y + (int)(tecMovementSpeed * direction->Y));
			}

			// Проверяем, достиг ли корабль чекпоинта
			if (CurrentPath->CheckValidate(CurrentLocation(), ABS_maxMovementSpeed)) {
				turningDirection->TurningWasSelected = 0;
				if (reverseGear == 1) {
					direction->angle -= 180;
					maxMovementSpeed = ABS_maxMovementSpeed_;
					tecMovementSpeed = -1;
				}
				reverseGear = 0;
				CheckLastAngle = 1;
			}
		}
		else {
			pictureBox->Invalidate();
		}


		if (CurrentPath->CheckFinal()) {
			maxMovementSpeed = -1;
			tecMovementSpeed = -1;
			TransportIsFinished(this);
		}
		else
		{
			if (!shutdown) {
				if (reverseGear == 1) maxMovementSpeed = ABS_maxMovementSpeed_ / 2;
				else maxMovementSpeed = ABS_maxMovementSpeed_;
			}
		}
	}


	//ТекущийПутьДвижения
	property Path^ CurrentPath {
		void set(Path^ path) {
			if (CurrentPath != nullptr && CurrentPath->PathEnded != nullptr) {
				TransportIsFinished -= _CurrentPath->PathEnded;
			}
			// Устанавливаем новый путь
			_CurrentPath = path;
			
			// Добавляем обработчик события PathEnded новому пути
			if (_CurrentPath != nullptr && _CurrentPath->PathEnded != nullptr) {
				TransportIsFinished += _CurrentPath->PathEnded;
			}
			
			
		}
		Path^ get() {
			return _CurrentPath;
		}
	}
	
	Path^ _CurrentPath;
	void CorrectDirection() {
		direction->angle = CurrentPath->calculateDirection(CurrentLocation());
		RotatePictureBox(direction->angle);
		hitBox->EditZones(CurrentLocation());
	}
	//Метод проверки возможности поворота
	bool CheckRotate(float angle) {


		Point center = CurrentLocation();
		array<Point>^ points = gcnew array<Point>(4);
		points[0] = System::Drawing::Point(-ImageObj_->Width / 2.0 + center.X, -ImageObj_->Height / 2.0 + center.Y);
		points[1] = System::Drawing::Point(ImageObj_->Width / 2.0 + center.X, -ImageObj_->Height / 2.0 + center.Y);
		points[2] = System::Drawing::Point(ImageObj_->Width / 2.0 + center.X, ImageObj_->Height / 2.0 + center.Y);
		points[3] = System::Drawing::Point(-ImageObj_->Width / 2.0 + center.X, ImageObj_->Height / 2.0 + center.Y);

		// Создаем матрицу трансформации для поворота
		System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();
		matrix->RotateAt(angle, center);

		matrix->TransformPoints(points);

		for (int i = 0; i < All_Transport()->Length; i++)
		{
			Transport^ obj_2 = All_Transport()[i];
			Transport^ obj_1 = this;

			if (obj_2 == this) continue;
			if (CheckIntersectingHitBox(obj_1->hitBox->RedZone, obj_2->hitBox->RedZone)) {
				if (obj_1->Transport_ID > obj_2->Transport_ID) {
					return false;
				}
				else {
					return true;
				}
			}
			if (hitBox->CheckIntersecting(points, obj_2->hitBox->RedZone)) return false;
		}
		return true;
	}


	//Метод поворота
	void RotatePictureBox(float angle)
	{
		// Проверяем, что в pictureBox есть изображение
		if (pictureBox->Image != nullptr)
		{
			hitBox->RotatePoints(angle, ImageObj_);

			//Вот тут новые координаты хитбокса корабля
			//Вызовем хитбоксы на переопределение, с применением поворота и у нас будут хранться там точки 

			// Вычисляем новые размеры для PictureBox
			double minX = std::min(std::min(hitBox->TopLeft.X, hitBox->TopRight.X), std::min(hitBox->BotRight.X, hitBox->BotLeft.X));
			double maxX = std::max(std::max(hitBox->TopLeft.X, hitBox->TopRight.X), std::max(hitBox->BotRight.X, hitBox->BotLeft.X));
			double minY = std::min(std::min(hitBox->TopLeft.Y, hitBox->TopRight.Y), std::min(hitBox->BotRight.Y, hitBox->BotLeft.Y));
			double maxY = std::max(std::max(hitBox->TopLeft.Y, hitBox->TopRight.Y), std::max(hitBox->BotRight.Y, hitBox->BotLeft.Y));
			int newWidth = abs(maxX - minX);
			int newHeight = abs(maxY - minY);


			// Создаем матрицу трансформации для поворота
			System::Drawing::Drawing2D::Matrix^ matrix1 = gcnew System::Drawing::Drawing2D::Matrix();
			matrix1->RotateAt(angle, System::Drawing::PointF(newWidth / 2, newHeight / 2));


			// Создаем новый Bitmap для повернутого изображения с новыми размерами
			System::Drawing::Bitmap^ rotatedImage = gcnew System::Drawing::Bitmap(newWidth, newHeight);

			// Применяем поворот
			{
				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(rotatedImage);
				g->Transform = matrix1;
				g->DrawImage(ImageObj_, Rectangle(newWidth / 2 - ImageObj_->Width / 2, newHeight / 2 - ImageObj_->Height / 2, ImageObj_->Width, ImageObj_->Height)); // Рисуем изображение с учетом смещения
				delete g;
			}

			// Устанавливаем повернутое изображение в PictureBox
			pictureBox->Image = rotatedImage;

			// Устанавливаем положение и новые размеры для PictureBox
			pictureBox->Location = Point(pictureBox->Location.X + pictureBox->Width / 2 - newWidth / 2, pictureBox->Location.Y - newHeight / 2 + pictureBox->Height / 2);
			pictureBox->Width = newWidth;
			pictureBox->Height = newHeight;
		}
	}

	bool segmentsIntersect(Point p1, Point p2, Point p3, Point p4) {
		double det = (p2.X - p1.X) * (p4.Y - p3.Y) - (p4.X - p3.X) * (p2.Y - p1.Y);
		if (det == 0) { // отрезки параллельны или лежат на одной прямой
			// Проверяем, лежат ли точки начала и конца одного отрезка по обе стороны от другого отрезка
			if ((p3.X - p1.X) * (p3.X - p2.X) > 0 || (p4.X - p1.X) * (p4.X - p2.X) > 0 ||
				(p3.Y - p1.Y) * (p3.Y - p2.Y) > 0 || (p4.Y - p1.Y) * (p4.Y - p2.Y) > 0)
				return false;
			// Один отрезок является частью другого
			if (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4)
				return true;
			return false;
		}

		double lambda = ((p4.Y - p3.Y) * (p4.X - p1.X) + (p3.X - p4.X) * (p4.Y - p1.Y)) / det;
		double gamma = ((p1.Y - p2.Y) * (p4.X - p1.X) + (p2.X - p1.X) * (p4.Y - p1.Y)) / det;

		return (0 <= lambda && lambda <= 1) && (0 <= gamma && gamma <= 1);
	}

	bool CheckIntersectingHitBox(array<Point>^ Points_sh1, array<Point>^ Points_sh2) {
		// Проверяем пересечение
		for (int i = 0; i < 4; ++i) {
			Point p1 = Points_sh1[i];
			Point p2 = Points_sh1[(i + 1) % 4];

			for (int j = 0; j < 4; ++j) {
				Point p3 = Points_sh2[j];
				Point p4 = Points_sh2[(j + 1) % 4];

				if (segmentsIntersect(p1, p2, p3, p4)) {
					return true;
				}
			}
		}
		return false;
	}

	//Проверка столкновения
	void CheckCollisions() 
	{
		for (int i = 0; i < All_Transport()->Length; i++)
		{
			Transport^ obj_1 = this;
			Transport^ obj_2 = All_Transport()[i];

			if (obj_2 == obj_1) continue;
			
			if (CheckIntersectingHitBox(obj_1->hitBox->RedZone, obj_2->hitBox->RedZone)) {
				if (obj_1->Transport_ID > obj_2->Transport_ID) {
					obj_1->shutdown = 1;
					obj_1->maxMovementSpeed = 0;
					obj_1->tecMovementSpeed = 0;
				}
				else {
					obj_1->shutdown = 0;
				}
				break;
			}
			else obj_1->shutdown = 0, maxMovementSpeed = 10;
			// Получаем абсолютные границы хитбоксов каждого корабля
			array<Point>^ Points_sh1 = obj_1->hitBox->GreenZone;
			array<Point>^ Points_sh2 = obj_2->hitBox->GreenZone;

			bool intersecting = CheckIntersectingHitBox(Points_sh1, Points_sh2);

			// Проверяем пересечение областей pictureBox двух кораблей
			if (intersecting)
			{
				//Проверка 1 смотрит на 2 то мы его останавливаем
				if (isLookingAtSquare(obj_1->CurrentLocation(), Point(obj_1->CurrentLocation().X + 400 * obj_1->direction->X, obj_1->CurrentLocation().Y + 400 * obj_1->direction->Y), Points_sh2)) {

					//Если ещё и 2 смотрит на 1
					if (isLookingAtSquare(obj_2->CurrentLocation(), Point(obj_2->CurrentLocation().X + obj_2->pictureBox->Width * obj_2->direction->X, obj_2->CurrentLocation().Y + obj_2->pictureBox->Height * obj_2->direction->Y), Points_sh1)) {
						//Если корабль будет смотреть на корабль который смотрит на него то аларм, особый случай
						PointF center1 = obj_1->CurrentLocation();
						PointF center2 = obj_2->CurrentLocation();
						PointF front1 = PointF(obj_1->CurrentLocation().X + 400 * obj_1->direction->X, obj_1->CurrentLocation().Y + 400 * obj_1->direction->Y);
						PointF front2 = PointF(obj_2->CurrentLocation().X + 400 * obj_2->direction->X, obj_2->CurrentLocation().Y + 400 * obj_2->direction->Y);

						//Находим точку пересечения их направлений и едет тот кто ближе к проблемной точке
						PointF dotCross = Cramer(-(center1.Y - front1.Y), (center1.X - front1.X), (center1.X - front1.X) * front1.Y - (center1.Y - front1.Y) * front1.X, -(center2.Y - front2.Y), (center2.X - front2.X), (center2.X - front2.X) * front2.Y - (center2.Y - front2.Y) * front2.X);
						double d_sh1 = sqrt((dotCross.X - center1.X) * (dotCross.X - center1.X) + (dotCross.Y - center1.Y) * (dotCross.Y - center1.Y));
						double d_sh2 = sqrt((dotCross.X - center2.X) * (dotCross.X - center2.X) + (dotCross.Y - center2.Y) * (dotCross.Y - center2.Y));

						if (d_sh2 > d_sh1) continue;
						else if (d_sh2 < d_sh1) {
							obj_1->shutdown = 1;
							obj_1->maxMovementSpeed = 0;
							obj_1->tecMovementSpeed = 0;
							break;
						}
						else{
							if (obj_1->Transport_ID < obj_2->Transport_ID) continue;
							else {
								obj_1->shutdown = 1;
								obj_1->maxMovementSpeed = 0;
								obj_1->tecMovementSpeed = 0;
								break;
							}
						}
					}
					else {
						obj_1->shutdown = 1;
						obj_1->maxMovementSpeed = 0;
						obj_1->tecMovementSpeed = 0;
						break;
					}
				}
				else
				{
					obj_1->shutdown = 0;
				}
			}
			else
			{
				obj_1->shutdown = 0;
			}
		}
	}
	
	// Функция, которая проверяет, смотрит ли вектор на квадрат
	bool isLookingAtSquare(Point center, Point p4, array<Point>^ points) {

		bool intersecting = false;
		for (int i = 0; i < 4; ++i) {
			Point p1 = points[i];
			Point p2 = points[(i + 1) % 4];

			if (segmentsIntersect(p1, p2, center, p4)) {
				intersecting = true;
				break;
			}
		}
		return intersecting;
	}
	PointF Cramer(float a1, float b1, float d1, float a2, float b2, float d2) {
		float dx = d1 * b2 - b1 * d2;
		float dy = a1 * d2 - d1 * a2;
		float d = a1 * b2 - b1 * a2;
		float x = dx / d;
		float y = dy / d;
		return PointF(x, y);
	}

	property int tecMovementSpeed {
		void set(int x) {
			if (x == -1) tecMovementSpeed_ = 0;
			else {
				int difference = x - tecMovementSpeed_;
				if (abs(difference) <= 2) {
					tecMovementSpeed_ = x;
				}
				else {
					int maxStep = 3; // Максимальный шаг изменения скорости
					int minStep = 2; // Минимальный шаг изменения скорости

					// Вычисляем коэффициент для определения размера шага
					double coefficient = std::min(1.0, abs(difference) / 10.0);

					// Рассчитываем шаг изменения скорости с учетом коэффициента
					int changeAmount = int(maxStep * (1.0 - coefficient)) + minStep;

					// Применяем знак разницы к шагу
					changeAmount *= (difference > 0) - (difference < 0);

					tecMovementSpeed_ += changeAmount;
				}
			}
		}
		int get() {
			return tecMovementSpeed_;
		}
	}
	property int ABS_maxMovementSpeed {
		int get() {
			return ABS_maxMovementSpeed_;
		}
	}
	int tecMovementSpeed_ = 0;

	HitBox^ hitBox;

	
	public:
		property Image^ ImageObj {
			Image^ get() {
				return ImageObj_;
			}
		}
		property Image^ ImageBase {
			Image^ get() {
				return ImageBase_;
			}
		}

		virtual void SetImage(int i) {
			if (i < 0 || i >= ImagesObj->Length) i = 0;
			ImageObj_ = ImagesObj[i];
			hitBox = gcnew HitBox(ImageObj_);
			RefreshImgObj();
		}

		array<Image^>^ ImagesObj;
		array<Image^>^ ImagesBase;

		PictureBox^ pictureBox;
		
public:bool shutdown = 0;//Остановка 
	protected:
		Image^ ImageObj_;
		Image^ ImageBase_;
		
		double angleSpread = 4;
		bool reverseGear = 0;//ЗаднийХод
		//Скорость передвижения (пикселей за тик)
		int maxMovementSpeed = ABS_maxMovementSpeed_;
		int ABS_maxMovementSpeed_;

		int angularSpeed = ABS_AngularSpeed; //Угловая скорость (Максимальные градусы за тик);
		int ABS_AngularSpeed;
		Turning^ turningDirection;

		double lastAngle = 0;
		bool CheckLastAngle = 1;

		//ОбновлениеИзображенияКорабля
		void RefreshImgObj() {
			pictureBox->Location = Point(pictureBox->Location.X + pictureBox->Width / 2 - ImageObj_->Width/2, pictureBox->Location.Y + pictureBox->Height / 2 - ImageObj_->Height/2);
			pictureBox->Width = ImageObj_->Width; // Установите ширину изображения
			pictureBox->Height = ImageObj_->Height; // Установите высоту изображения
			pictureBox->Image = ImageObj_;
		}
};
ref class Box {
public:
	static PictureBoxPaintHandler^ handler;
	Box(int i) {
		pictureBox = gcnew PictureBox();
		pictureBox->SizeMode = PictureBoxSizeMode::CenterImage;
		ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());

		if (i < 1 || i > 4) i = 1;
		image = dynamic_cast<Image^>(rm->GetObject("Container_" + i));
		pictureBox->Image = image;
		pictureBox->Width = pictureBox->Image->Width;
		pictureBox->Height = pictureBox->Image->Height;

		color = i;
	}
	
	~Box(){
		pictureBox->Width = 1;
		pictureBox->Height = 1;
	}
	void Print(Point loc, System::Windows::Forms::Form^ frm) {
		frm->Controls->Add(pictureBox);
		pictureBox->BringToFront();
		Transport::All_PictureBox[0]->SendToBack();
		
		pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(handler, &PictureBoxPaintHandler::Invoke);
		pictureBox->Location = loc;
	}

	property Point Location {
		void set(Point M) {
			pictureBox->Location = M;
		}
		Point get() {
			return pictureBox->Location;
		}
	}

	property int Color {
		int get() {
			return color;
		}
	}

	property Image^ BoxImage {
		Image^ get() {
			return image;
		}
	}

	PictureBox^ pictureBox;
private:
	Image^ image;
	int color;
};


ref class Freight {
private:
	Random^ rnd = gcnew Random;
	System::Windows::Forms::Form^ frm;
public:
	array<Point>^ points;
	array<Box^>^ Boxs;

	Freight(array<Point>^ mas, Image^ image, Point center, System::Windows::Forms::Form^ f) {
		points = mas;
		int len = mas->Length;
		frm = f;
		Boxs = gcnew array<Box^>(len);
		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(image);

		for (int i = 0; i < len; i++) {
			int color = rnd->Next(1, 4);

			Box^ box = gcnew Box(color);
			g->DrawImage(box->BoxImage, Rectangle(mas[i], Size(box->BoxImage->Width, box->BoxImage->Height)));

			Boxs[i] = box;
		}
	}

	void SetBox(Box^ box, int i, Image^ image) {
		Boxs[i] = box;
		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(image);
		Image^ imageBox = box->BoxImage;
		g->DrawImage(imageBox, Rectangle(points[i], Size(box->BoxImage->Width, box->BoxImage->Height)));
	}


};

public delegate void RequestValidationHandler(int i);
public delegate void ShipArrivedToPortHandler(int i, Object^ sender);
public delegate void ShipSailsFromPortHandler(int i);
public delegate void ShipLeavePortHandler(int i);

ref class Ship : public Transport {
public:
	static int timeSpawn;

	virtual array<Transport^>^ All_Transport() override {
		return All_Ships;
	}

	//Delegates
	RequestValidationHandler^ ValidationAvaible;
	ShipSailsFromPortHandler^ ShipCanSail;

	//Events
	static event RequestValidationHandler^ RequestValidation;
	static event ShipArrivedToPortHandler^ ShipArrivedToPort;
	static event ShipLeavePortHandler^ ShipLeavePort;
	

	void RaiseRequestValidation(int i);
	void RaiseShipLeavePort(int i);
	void OnValidationAvaible(int i);
	void OnShipCanSail(int i);

	virtual void RaiseShipArrivedToPort(int i);

	static array<Transport^>^ All_Ships = gcnew array<Transport^>{};
	static int current_ID = 0;

	virtual void InitializationShip(int i) {
		ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());
		ImagesObj = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("ShipCruise_1"), rm->GetObject("ShipCruise_2"))}; //Инициализируем массив изображений корабля
		SetImage(i);
		CurrentPath = gcnew Path(4); //Определили начальный путь
		CorrectDirection();
		//При спавне генерируем случаеное значение для нового таймспавна
		Random^ rnd = gcnew Random();
		timeSpawn = 1000 * rnd->Next(50, 100);
	}

	Ship(Point loc, int i) : Transport(loc) {
		ValidationAvaible = gcnew RequestValidationHandler(this, &Ship::OnValidationAvaible);
		ShipCanSail = gcnew ShipSailsFromPortHandler(this, &Ship::OnShipCanSail);
		Transport_ID_ = current_ID++;

		// Добавление этого корабля в массив All_Shipps
		Array::Resize(All_Ships, All_Ships->Length + 1);
		All_Ships[All_Ships->Length - 1] = this;

		ABS_maxMovementSpeed_ = 10; // 8?
		angularSpeed = 10;//2?
		InitializationShip(i);
	}

	~Ship() {
		List<Transport^>^ newAll_Ships = gcnew List<Transport^>(All_Ships);
		newAll_Ships->Remove(this);
		All_Ships = newAll_Ships->ToArray();
		List<PictureBox^>^ newAll_PictureBox = gcnew List<PictureBox^>(All_PictureBox);
		newAll_PictureBox->Remove(this->pictureBox);
		All_PictureBox = newAll_PictureBox->ToArray();
	}
};

ref class ShipCargo : public Ship{
public:
	static int timeSpawn;

	virtual void SetImage(int i) override{
		if (i < 0 || i >= ImagesObj->Length) i = 0;
		ImageObj_ = ImagesObj[i];
		ImageBase_ = ImagesBase[i];
		hitBox = gcnew HitBox(ImageObj_);
		RefreshImgObj();
	}

	virtual void RaiseShipArrivedToPort(int i) override;

	virtual void InitializationShip(int i) override {
		//Инициализация базового изображения
		ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());

		ImagesObj = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("ShipСargo_1"))}; //Инициализируем массив изображений корабля
		ImagesBase = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("Paluba_1"))}; //Инициализируем массив изображений подложек корабля

		SetImage(0);
		
		All_PictureBox[0]->SendToBack();

		CurrentPath = gcnew Path(0); //Определили начальный путь
		
		//При спавне генерируем случаеное значение для нового таймспавна
		Random^ rnd = gcnew Random();
		timeSpawn = 1000 * rnd->Next(300, 400);
	}

	ShipCargo(Point loc, int i) : Ship(loc, i) {
		CreateFreight(i);
		CorrectDirection();
	};

	void CreateFreight(int i) {
		if (i < 0 || i >= ImagesObj->Length) i = 0;
		if (i == 0) freight = gcnew Freight(gcnew array<Point> {Point(79, 8), Point(101, 8), Point(123, 8),
			Point(79, 17), Point(101, 17), Point(123, 17),
			Point(79, 27), Point(101, 27), Point(123, 27),
			Point(79, 36), Point(101, 36), Point(123, 36)}, ImageObj, CurrentLocation(), frm);
	}
	
	Box^ TakeBox(int i) {
			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(ImageObj);
			Box^ box = freight->Boxs[i];
			g->DrawImage(ImageBase, Rectangle(freight->points[i], Size(box->BoxImage->Width, box->BoxImage->Height)));
			box->Print(Point(freight->points[i].X + pictureBox->Location.X, freight->points[i].Y + pictureBox->Location.Y), frm);
			return box;
		}
	
	~ShipCargo() {
		List<Transport^>^ newAll_Ships = gcnew List<Transport^>(All_Ships);
		newAll_Ships->Remove(this);
		All_Ships = newAll_Ships->ToArray();
		List<PictureBox^>^ newAll_PictureBox = gcnew List<PictureBox^>(All_PictureBox);
		newAll_PictureBox->Remove(this->pictureBox);
		All_PictureBox = newAll_PictureBox->ToArray();
	}
	
	Freight^ freight;
};


ref class Car : public Transport {
public:
	static int timeSpawn;
	virtual array<Transport^>^ All_Transport() override {
		return All_Cars;
	}

	static array<Transport^>^ All_Cars = gcnew array<Transport^>{};
	static int current_ID = 0;

	static bool srandCheck = 0;

	virtual void InitializationCar() {
		ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());

		ImagesObj = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("CarSimple_1")), dynamic_cast<Image^>(rm->GetObject("CarSimple_2")), dynamic_cast<Image^>(rm->GetObject("CarSimple_3")), dynamic_cast<Image^>(rm->GetObject("CarSimple_4"))}; //Инициализируем массив изображений корабля

		SetImage(rand() % 4);

		// Добавление этой машины в массив All_Car
		Array::Resize(All_Cars, All_Cars->Length + 1);
		All_Cars[All_Cars->Length - 1] = this;


		angleSpread = 2;

		ABS_maxMovementSpeed_ = 7;
		angularSpeed = 20;

		hitBox->YZ_max_chislo = 0;
		hitBox->YZ_min_chislo = 0;
		hitBox->GZ_max_chislo = 1;
		hitBox->GZ_min_chislo = 1;

		if (!srandCheck) srand(time(0)), srandCheck = 1;

		Point loc;
		if (rand() % 2) {
			//Допустим вверх спаним и путь тот который на верх
			loc = Point(50, 1100);	
			CurrentPath = gcnew Path(gcnew array<Point> {Point(60, 1079), Point(94, 1028), Point(122, 984), Point(135, 941), Point(137, 894), Point(113, 813), Point(106, 759), Point(99, 685), Point(76, 643), Point(46, 599), Point(27, 549), Point(20, 502), Point(0, 473), Point(-20, 460)}, DeleteHandler);
		}
		else
		{
			loc = Point(-30, 500);
			CurrentPath = gcnew Path(gcnew array<Point> {Point(-10, 528), Point(0, 576), Point(10, 603), Point(30, 632), Point(52, 665), Point(66, 705), Point(70, 758), Point(77, 805), Point(90, 845), Point(101, 880), Point(103, 915), Point(95, 962), Point(74, 999), Point(43, 1035), Point(20, 1068), Point(8, 1079), Point(-10, 1100)}, DeleteHandler);
		}
		print(loc, frm);
		CorrectDirection();
		All_PictureBox[0]->SendToBack();
		Random^ rnd = gcnew Random();
		timeSpawn = 1000 * rnd->Next(1, 5);
	}
	
	Car() : Transport() {
		DeleteHandler = gcnew FinishPathHandler(this, &Car::CarLeftScreen);
		InitializationCar();
		
		//конструктор
		Array::Resize(All_PictureBox, All_PictureBox->Length + 1);
		All_PictureBox[All_PictureBox->Length - 1] = pictureBox;
		
		pictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(handler, &PictureBoxPaintHandler::Invoke);
				
		Transport_ID_ = current_ID++;
	}
	
	~Car() {
		List<Transport^>^ newAll_Cars = gcnew List<Transport^>(All_Cars);
		newAll_Cars->Remove(this);
		All_Cars = newAll_Cars->ToArray();
		
		DeletePictureBox();
	}

	FinishPathHandler^ DeleteHandler;

	void CarLeftScreen(Object^ sender) {
		//Удаляем машину
		delete this;
	}
};

ref class CarTech : public Car {
public:
	virtual void SetImage(int i) override {
		if (i < 0 || i >= ImagesObj->Length) i = 0;
		ImageObj_ = ImagesObj[i];
		ImageBase_ = ImagesBase[i];
		hitBox = gcnew HitBox(ImageObj_);
		RefreshImgObj();
	}

	virtual array<Transport^>^ All_Transport() override {
		return All_CarsTech;
	}

	static array<Transport^>^ All_CarsTech = gcnew array<Transport^>{};
	static int current_ID = 0;

	virtual void InitializationCar() override{
		ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());

		ImagesObj = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("CarTech"))}; //Инициализируем массив изображений корабля
		ImagesBase = gcnew array<Image^>{dynamic_cast<Image^>(rm->GetObject("CarTech_Base"))}; //Инициализируем массив изображений подложек корабля

		SetImage(0);

		angleSpread = 0;
		// Добавление этой машины в массив All_CarTechs
		Array::Resize(All_CarsTech, All_CarsTech->Length + 1);
		All_CarsTech[All_CarsTech->Length - 1] = this;

		ABS_maxMovementSpeed_ = 7;
		angularSpeed = 18;

		hitBox->YZ_max_chislo = 6;
		hitBox->YZ_min_chislo = 4;
		hitBox->GZ_max_chislo = 15;
		hitBox->GZ_min_chislo = 6;
	}

	CarTech(Point loc, FinishPathHandler^ handler) :Car() {
		CurrentPath = gcnew Path(gcnew array<Point> {Point(949, 1079), Point(950, 1030), Point(974, 1006), Point(1010, 987), Point(1030, 987)}, handler);
		print(loc, frm);
		All_PictureBox[0]->SendToBack();
		CorrectDirection();
	}
	
	CarTech(Point loc, FinishPathHandler^ handler, Box^ box_) : CarTech(loc, handler) {
		box = box_;
		//Рисуем на машине контейнер
		System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(ImageObj);
		Image^ image = box->BoxImage;
		g->DrawImage(image, Rectangle(locForBox, System::Drawing::Size(image->Width, image->Height)));
		pictureBox->Image = ImageObj;	
	}
	~CarTech(){
		List<Transport^>^ newAll_CarTechs = gcnew List<Transport^>(All_CarsTech);
		newAll_CarTechs->Remove(this);
		All_CarsTech = newAll_CarTechs->ToArray();
		DeletePictureBox();
	}

	
	Point locForBox = Point(7,2);
	Box^ box;
};


public ref class PointWithDirection {
public:
	Point Position;
	int Angle; // Угол направления движения (в градусах)
	int speed;
	Color color;
	bool GoTop;
	bool ShipOnRightSide;
	PointWithDirection(Point position, int angle, Color clr, bool dir, int spd, bool side) {
		Position = position;
		Angle = angle;
		color = clr;
		GoTop = dir;
		ShipOnRightSide = side;
		speed = spd;
	}

	// Метод для обновления положения точки
	void Move(int areaWidth, int areaHeight) {
		//Если принадлежит прямой 
		if (ShipOnRightSide) {
			if (Position.Y <= areaWidth - Position.X && GoTop) {
				Angle = 45;
			}
		}
		else {
			if (Position.Y <= areaWidth + Position.X && GoTop) {
				Angle = -45;
			}
		}
		int deltaX = static_cast<int>(speed * Math::Sin(Math::PI * Angle / 180));
		int deltaY = speed;
		// Проверяем, не выходит ли точка за границы области по X
		if (Position.X + deltaX < 0 || Position.X + deltaX >= areaWidth) {
			// Если выходит, двигаем точку вдоль боковой границы
			deltaX = 0;
		}
		Position = Point(Position.X + deltaX, GoTop ? Position.Y - deltaY: Position.Y + deltaY);
	}

	// Метод для изменения направления точки
	void ChangeDirection(int maxAngleChange, Random^ random, int areaWidth) {
		int angleChange;
		
		if (Position.X == areaWidth) {
			angleChange = random->Next(-maxAngleChange, 0);
		}
		else if(Position.X == 0){
			angleChange = random->Next(0, maxAngleChange);
		}
		else {
			angleChange = random->Next(-maxAngleChange, maxAngleChange + 1);
		}

		Angle += angleChange;
	}
};

ref class Port {
public:
	
	ref class Dock {
	public:
		System::Windows::Forms::Form^ frm;
		Dock(System::Windows::Forms::Form^ frm_) {
			frm = frm_;
			ResourceManager^ rm = gcnew ResourceManager("TP_Project.Resource", System::Reflection::Assembly::GetExecutingAssembly());
			
			//Инициализируем наш кран
			cran = (gcnew System::Windows::Forms::PictureBox());
			cran->BackColor = System::Drawing::Color::Transparent;
			cran->Image = (cli::safe_cast<System::Drawing::Image^>(rm->GetObject("Crane")));
			cran->Location = System::Drawing::Point(1088, 915);
			cran->Size = System::Drawing::Size(32, 104);
			
			frm->Controls->Add(cran);
			Transport::All_PictureBox[0] = cran;

			timerCran = gcnew Timer;
			timerCran->Tick += gcnew System::EventHandler(this, &Port::Dock::timerCran_Tick);

			PictureBoxPaintHandler^ Boxhandler = gcnew PictureBoxPaintHandler(this, &Port::Dock::Box_Paint);
			Box::handler = Boxhandler;
		}
		Dock(System::Windows::Forms::Form^ frm_, Point loc) : Dock(frm_) {
			cran->Location = loc;
		}
		~Dock(){
			frm->Controls->Remove(cran);
			delete timerCran;
		}
		bool flagSpawn = 1;
		bool flagBoxNeedCar = 1;
		bool flagBoxReadyPrint = 0;
		bool carReady = 0;
		bool flagCranOnPosition = 0;
		int CounterSpawnCar = 0;
		int timeSpawn = -1;
		int tecTime;
		bool flagShipWasUnloaded = 0;
		bool flagShipWasLoaded = 0;
		bool flagCranBusy = 0;
		ShipCargo^ ship;
		PictureBox^ cran;
		Timer^ timerCran;

		void refresh() {
			 flagSpawn = 1;
			 flagBoxNeedCar = 1;
			 flagBoxReadyPrint = 0;
			 carReady = 0;
			 flagCranOnPosition = 0;
			 CounterSpawnCar = 0;
			 timeSpawn = -1;
			 flagShipWasUnloaded = 0;
			 flagShipWasLoaded = 0;
			 flagCranBusy = 0;
			 tecNum = 0;
			 ship = nullptr;
		}

		Box^ box;
		PointF^ requiredPos;
		
		int tecNum = 0;
		void TakeCoordinates() {
			Point shipLoc = ship->pictureBox->Location;
			Point boxLoc = ship->freight->points[tecNum];
			requiredPos = PointF(shipLoc.X + boxLoc.X + 21/2, shipLoc.Y + boxLoc.Y + 9/2);
		}
		
		void timerCran_Tick(System::Object^ sender, System::EventArgs^ e) {
			//Двигаем все технические машины
			for (int m = 0; m < 1; m++) {
				if (CarTech::All_CarsTech->Length == 0) timerCran->Enabled = 0;
				for (int i = 0; i < CarTech::All_CarsTech->Length; i++)
				{
					CarTech::All_CarsTech[i]->moving();
				}
				if (ship != nullptr) {

					if (flagShipWasLoaded) {
						//Вызов события отплытия порта
						ShipCanSailFromPort0(0);

						return;
					}
					//Если корабль еще не был разгружен
					if (!flagShipWasUnloaded) {
						UnloadingShip(cran, gcnew FinishPathHandler(this, &Port::Dock::TechCarReady));
					}
					else {
						LoadingShip(cran, gcnew FinishPathHandler(this, &Port::Dock::TechCarWithBoxReady));
					}

				}
			}
		}
		
		void DockStartWorking(Object^ sender) {
			ShipCargo^ ship_ = dynamic_cast<ShipCargo^>(sender);
			ship = ship_;
			//Включаем таймер по которому будет передвигаться кран
			timerCran->Enabled = true;
		}

		void Box_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			PictureBox^ pb1 = (PictureBox^)sender;
			PictureBox^ pb2 = cran;

			if (pb1 != pb2 && pb1->Bounds.IntersectsWith(pb2->Bounds)) {
				// Определяем разницу между верхними границами pb1 и pb2
				int offsetY = pb2->Top - pb1->Top;
				int offsetX = pb2->Left - pb1->Left;

				Image^ image = pb2->Image;
				// Отрисовываем изображение pb2 в области пересечения на pb1
				e->Graphics->DrawImage(image, offsetX, offsetY, image->Width, image->Height);
			}
		}

		void UnloadingShip(PictureBox^ cran, FinishPathHandler^ handler) {
			if (tecNum >= ship->freight->Boxs->Length) {
				tecNum--;
				requiredPos = nullptr;
				flagShipWasUnloaded = 1;
				flagSpawn = 1;
				CounterSpawnCar = 0;
				return;
			}
			SpawnTechCar(handler);
			//ЕСЛИ МЫ ЕЩЕ НЕ ВЗЯЛИ КОНТЕЙНЕР
			if (box == nullptr) {
				//Если мы еще не взяли координату берем
				if (!requiredPos) TakeCoordinates();
				//Иначе если кран еще не прировнялся двигаем кран к координатам
				double centerWidthCran = cran->Location.X + cran->Width / 2;
				int step = 1;
				if (abs(centerWidthCran - requiredPos->X) > 1 || centerWidthCran < requiredPos->X) {
					if (abs(centerWidthCran - requiredPos->X) <= step) cran->Location = Point((int)requiredPos->X - cran->Width / 2, cran->Location.Y);
					else if (centerWidthCran < requiredPos->X) cran->Location = Point(cran->Location.X + step, cran->Location.Y);
					else if (centerWidthCran > requiredPos->X) cran->Location = Point(cran->Location.X - step, cran->Location.Y);
					ship->pictureBox->Invalidate();
				}
				else {
					box = ship->TakeBox(tecNum); //берем контейнер (только если)
					flagBoxNeedCar = 1;
					flagSpawn = 1;
				}
			}
			//ИНАЧЕ
			else if (carReady) {
				//двигаем контейнер вниз
				int step = 3;
				int y = 987 - box->pictureBox->Height / 2;
				//если достиг у - h/2, то мы рисуем на машине контейнер, а сам контейнер удаляем, меняем маршрут машине на выезд, flagSpawn = 1, говорим брать некст контейнер
				if (box->Location.Y != y) {
					if (abs(box->Location.Y - 987) <= step) box->Location = Point(box->Location.X, y);
					else box->Location = Point(box->Location.X, box->Location.Y + step);
					box->pictureBox->Invalidate();
				}
				else {
					// мышине присваивается заморозка freezetime = 100;
					flagBoxReadyPrint = 1;
				}
			}
			
		}

		void LoadingShip(PictureBox^ cran, FinishPathHandler^ handler) {
			if (tecNum == -1) {
				tecNum = 0;
				flagShipWasLoaded = 1;
				return;
			}
			
			SpawnTechCarWithBox(handler);

			if (box == nullptr) {
				//Двигаем кран
				if (!requiredPos) TakeCoordinates();
				double centerWidthCran = cran->Location.X + cran->Width / 2;
				int step = 1;
				if (abs(centerWidthCran - requiredPos->X) > 1 || centerWidthCran < requiredPos->X) {
					if (abs(centerWidthCran - requiredPos->X) <= step) cran->Location = Point((int)requiredPos->X - cran->Width / 2, cran->Location.Y);
					else if (centerWidthCran < requiredPos->X) cran->Location = Point(cran->Location.X + step, cran->Location.Y);
					else if (centerWidthCran > requiredPos->X) cran->Location = Point(cran->Location.X - step, cran->Location.Y);
					ship->pictureBox->Invalidate();
				}
				else {
					//Прировнялся, то есть можно машине подъезжать
					flagCranOnPosition = 1;
				}
			}
			else {
				//Если есть бокс то двигаем его
				int step = 3;
				int y = ship->pictureBox->Location.Y + ship->freight->points[tecNum].Y;
				if (box->Location.Y != y) {
					if (abs(box->Location.Y - y) <= step) box->Location = Point(box->Location.X, y);
					else box->Location = Point(box->Location.X, box->Location.Y - step);
					box->pictureBox->Invalidate();
				}
				else {
					ship->freight->SetBox(box, tecNum, ship->ImageObj);
					delete box;
					box = nullptr;
					requiredPos = nullptr;
					tecNum--;
					flagCranBusy = 0;
					flagCranOnPosition = 0;
					flagSpawn = 1;
				}
			}
					
			}
		void SpawnTechCar(FinishPathHandler^ handler) {
			if (flagSpawn && CounterSpawnCar < ship->freight->Boxs->Length) {
				if (!timeSpawn) {
					int minTimeSpawn = 3;
					int maxTimeSpawn = 6;
					srand(time(0));
					timeSpawn = minTimeSpawn + rand() % (maxTimeSpawn - minTimeSpawn + 1);
				}
				tecTime += 100;
				if (timeSpawn * 1000 <= tecTime) {
					tecTime = 0;
					if (timeSpawn != -1) flagSpawn = 0;
					timeSpawn = 0;
					CarTech^ car = gcnew CarTech(Point(949, 1109), handler);
					CounterSpawnCar++;
				}
			}
		}
		void SpawnTechCarWithBox(FinishPathHandler^ handler) {
			if (flagSpawn && CounterSpawnCar < ship->freight->Boxs->Length) {
				if (!timeSpawn) {
					int minTimeSpawn = 3;
					int maxTimeSpawn = 6;
					srand(time(0));
					timeSpawn = minTimeSpawn + rand() % (maxTimeSpawn - minTimeSpawn + 1);
				}
				tecTime += 100;
				if (timeSpawn * 1000 <= tecTime) {
					tecTime = 0;
					if (timeSpawn != -1) flagSpawn = 0;
					timeSpawn = 0;
					srand(time(0));
					Box^ box = gcnew Box(1 + rand() % 4);
					CarTech^ car = gcnew CarTech(Point(949, 1109), handler, box);
					CounterSpawnCar++;
				}
			}
		}

		void TechCarReady(Object^ sender) {
			carReady = 1;
			CarTech^ techCar = dynamic_cast<CarTech^>(sender);
			if (flagShipWasUnloaded) {
				techCar->CurrentPath = gcnew Path(gcnew array<Point>{Point(1194, 987), Point(1351, 1040), Point(1370, 1060), Point(1370, 1200)}, gcnew FinishPathHandler(this, &Port::Dock::TechCarFinishCycle));
				return;
			}
			techCar->direction->angle = 0;
			techCar->RotatePictureBox(0);
			if (box && flagBoxNeedCar) {
				techCar->shutdown = 0;
				techCar->CurrentPath = gcnew Path(gcnew array<Point>{Point(box->Location.X + 17, 987)}, gcnew FinishPathHandler(this, &Port::Dock::TechCarRequestBox));
				flagBoxNeedCar = 0;
			}

		}
		void TechCarWithBoxReady(Object^ sender) {
			CarTech^ techCar = dynamic_cast<CarTech^>(sender);
			techCar->direction->angle = 0;
			techCar->RotatePictureBox(0);
			if (!flagCranBusy && flagCranOnPosition) {
				techCar->CurrentPath = gcnew Path(gcnew array<Point>{Point(cran->Location.X + techCar->ABS_maxMovementSpeed / 2 + cran->Width / 2, 987)}, gcnew FinishPathHandler(this, &Port::Dock::TechCarUnderCran));
				flagCranBusy = 1;
			}

		}
		void TechCarUnderCran(Object^ sender) {
			CarTech^ techCar = dynamic_cast<CarTech^>(sender);
			techCar->pictureBox->Location = Point(cran->Location.X + cran->Width / 2 - techCar->pictureBox->Width / 2 + 6, 987 - techCar->pictureBox->Height / 2); //Установим машину точно под кран 
			if (box == nullptr)
			{
				techCar->box->Print(Point(techCar->pictureBox->Location.X + techCar->locForBox.X, techCar->pictureBox->Location.Y + techCar->locForBox.Y), frm);
				box = techCar->box;
				//Убираем box с машины
				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(techCar->ImageObj);
				Image^ image = techCar->ImageBase;
				g->DrawImage(image, Rectangle(techCar->locForBox, System::Drawing::Size(image->Width, image->Height)));
				techCar->pictureBox->Image = techCar->ImageObj;
				techCar->CurrentPath = gcnew Path(gcnew array<Point>{Point(1194, 987), Point(1351, 1040), Point(1370, 1060), Point(1370, 1200)}, techCar->DeleteHandler);
				carReady = 0;
			}
		}

		void TechCarRequestBox(Object^ sender) {
			CarTech^ techCar = dynamic_cast<CarTech^>(sender);
			if (flagBoxReadyPrint) {
				System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(techCar->ImageObj);
				Image^ image = box->BoxImage;
				g->DrawImage(image, Rectangle(Point(box->Location.X - techCar->pictureBox->Location.X, box->Location.Y - techCar->pictureBox->Location.Y), System::Drawing::Size(image->Width, image->Height)));
				techCar->pictureBox->Image = techCar->ImageObj;
				flagBoxReadyPrint = 0;
				frm->Controls->Remove(box->pictureBox);
				box = nullptr;
				requiredPos = nullptr;
				tecNum++;
				techCar->CurrentPath = gcnew Path(gcnew array<Point>{Point(1194, 987), Point(1351, 1040), Point(1370, 1060), Point(1370, 1200)}, techCar->DeleteHandler);
				carReady = 0;
			}
		}

		void TechCarFinishCycle(Object^ sender) {
			//Удаляем машину
			CarTech^ techCar = dynamic_cast<CarTech^>(sender);
			delete techCar;
		}
	};

	Port::Dock^ dock;
	static bool flagShipInRedZone = false;

	ref class Berth {
	public:
		bool flagBerthWasOn;
		int areaWidth;
		int areaHeight;
		int counterPeople = 0;
		List<PointWithDirection^> points;
		Random^ random;
		int maxAngleChange = 15; // Максимальный угол изменения направления
		int maxSpeed = 5; // Максимальная скорость
		bool flagSpawnPeople = true;
		PictureBox^ pictureBox;
		bool ShipOnRightSide = 1;
		bool PeopleGoTop = false;
		Ship^ ship;
		Windows::Forms::Timer^ timer;
		Berth(PictureBox^ pct, bool side, Random^ rnd) {
			timer = gcnew Timer;
			random = rnd;
			timer->Tick += gcnew System::EventHandler(this, &Port::Berth::Timer_Tick);
			
			pct->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Port::Berth::PictureBox_Paint);
			pictureBox = pct;
			ShipOnRightSide = side;
			areaWidth = pictureBox->Width - 10;
			areaHeight = pictureBox->Height;
		}
		void refresh() {
			counterPeople = 0;
			flagSpawnPeople = true;
			PeopleGoTop = false;
			ship = nullptr;
		}
		void StartWorking(Object^ sender) {
			Ship^ ship_ = dynamic_cast<Ship^>(sender);
			ship = ship_;
			timer->Enabled = 1;
		}

		~Berth() {
			delete timer;
		}

		void Timer_Tick(System::Object^ sender, System::EventArgs^ e) {
			flagBerthWasOn = true;
			if (counterPeople == 0) {
				counterPeople = random->Next(30, 50);
				flagSpawnPeople = true;
			}
			if (counterPeople - 1 == 0) {
				flagSpawnPeople = false;
			}
			// Создаем новую точку с случайными координатами и добавляем ее в список точек
			if (random->NextDouble() < 1 && flagSpawnPeople) {
				//Считаем созданных людей
				counterPeople--;
				if (ShipOnRightSide) {
					if (!PeopleGoTop) {
						int x = areaWidth; // -10 чтобы точка не выходила за пределы области
						int y = 0; // Точка появляется сверху области
						points.Add(gcnew PointWithDirection(Point(x, y), random->Next(-maxAngleChange, 0), RandomColor(), PeopleGoTop, maxSpeed, ShipOnRightSide)); // Указываем начальный угол направления (90 градусов - вниз)
					}
					else {
						int x = 0; // -10 чтобы точка не выходила за пределы области
						int y = areaHeight - 10; // Точка появляется сверху области
						points.Add(gcnew PointWithDirection(Point(x, y), random->Next(0, maxAngleChange), RandomColor(), PeopleGoTop, maxSpeed, ShipOnRightSide)); // Указываем начальный угол направления (90 градусов - вниз)
					}
				}
				else{
					if (!PeopleGoTop) {
						int x = 0; // -10 чтобы точка не выходила за пределы области
						int y = 0; // Точка появляется сверху области
						points.Add(gcnew PointWithDirection(Point(x, y), random->Next(0, maxAngleChange), RandomColor(), PeopleGoTop, maxSpeed, ShipOnRightSide)); // Указываем начальный угол направления (90 градусов - вниз)
					}
					else {
						int x = areaWidth; // -10 чтобы точка не выходила за пределы области
						int y = areaHeight - 10; // Точка появляется снизу области
						points.Add(gcnew PointWithDirection(Point(x, y), random->Next(-maxAngleChange, 0), RandomColor(), PeopleGoTop, maxSpeed, ShipOnRightSide)); // Указываем начальный угол направления (90 градусов - вниз)
					}
				}
			}
			// Обновляем форму, чтобы отобразить новые позиции точек
			MovePoints();
			if (points.Count == 0 && !flagSpawnPeople) {
				if (!PeopleGoTop) PeopleGoTop = 1, counterPeople = 0;
				else if(!Port::flagShipInRedZone) {
					PeopleGoTop = 0;
					timer->Enabled = 0;
					flagBerthWasOn = false;
					//Вызов события отплытия порта
					
					ShipOnRightSide ? ShipCanSailFromPort1(1): ShipCanSailFromPort2(2);
					Port::flagShipInRedZone = true;
				}
			}
			pictureBox->Invalidate();
		}

		void MovePoints() {
			// Двигаем каждую точку
			for (int i = 0; i < points.Count; ++i) {
				points[i]->Move(areaWidth, areaHeight);

				// Изменяем направление точки редко, например, раз в секунду
				if (random->NextDouble() < 0.1) { // 10% вероятность изменения направления
					points[i]->ChangeDirection(maxAngleChange, random, areaWidth);
				}
			}

			// Удаляем точки, которые вышли за пределы области
			if (!PeopleGoTop) {
				for (int i = points.Count - 1; i >= 0; --i) {
					if (points[i]->Position.Y >= areaHeight) {
						points.RemoveAt(i);
					}
				}
			}
			else {
				for (int i = points.Count - 1; i >= 0; --i) {
					if (points[i]->Position.Y  <= 0) {
						points.RemoveAt(i);
					}
				}
			}
		}
		Color RandomColor() {
			Color clr;
			int i = random->Next(0, 3);
			if (i == 0) clr = Color::FromArgb(random->Next(150, 256), 0, 0);
			if (i == 1) clr = Color::FromArgb(0, random->Next(200, 256), 0);
			if (i == 2) clr = Color::FromArgb(0, 0, random->Next(150, 256));
			return clr;
		 }
		void PictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			Graphics^ g = e->Graphics;

			// Рисуем каждую точку
			for (int i = 0; i < points.Count; ++i) {
				SolidBrush^ brush = gcnew SolidBrush(points[i]->color);
				g->FillEllipse(brush, points[i]->Position.X, points[i]->Position.Y, 10, 10);
			}
		}
	};
	Random^ random = gcnew Random();
	Port::Berth^ berth1;
	Port::Berth^ berth2;
private:
	array <bool>^ Piers;
	System::Windows::Forms::Form^ frm;
public:

	//Events
	static event RequestValidationHandler^ ShipCanMoveToPort0;
	static event RequestValidationHandler^ ShipCanMoveToPort1;
	static event RequestValidationHandler^ ShipCanMoveToPort2;

	static event ShipSailsFromPortHandler^ ShipCanSailFromPort0;
	static event ShipSailsFromPortHandler^ ShipCanSailFromPort1;
	static event ShipSailsFromPortHandler^ ShipCanSailFromPort2;

	Port(System::Windows::Forms::Form^ frm_, PictureBox^ pct_LinePiers1, PictureBox^ pct_LinePiers2) {
		dock = gcnew Port::Dock(frm_);
		Piers = gcnew array <bool>{0, 0, 0};
		frm = frm_;
		pin_ptr<bool> pinnedPtr = &flagShipInRedZone;
		berth1 = gcnew Port::Berth(pct_LinePiers1, 1, random);
		berth2 = gcnew Port::Berth(pct_LinePiers2, 0, random);

		Ship::RequestValidation += gcnew RequestValidationHandler(this, &Port::CheckFeasibility);
		Ship::ShipArrivedToPort += gcnew ShipArrivedToPortHandler(this, &Port::OnShipArrivedToPort);
		
		Ship::ShipLeavePort += gcnew  ShipLeavePortHandler(this, &Port::LeavePier);
	}

	void OnShipArrivedToPort(int i, Object^ sender) {
		if (i == 0) dock->DockStartWorking(sender);
		else if (i == 1) berth1->StartWorking(sender);
		else if (i == 2) berth2->StartWorking(sender);
	}

	void CheckFeasibility(int i) {
		if (i == 0){
			if (!Piers[0]) Piers[0] = 1, ShipCanMoveToPort0(0);
		}
		else if (i == 1) {
			if (!flagShipInRedZone) {
				if(!Piers[1]) Piers[1] = 1, ShipCanMoveToPort1(1);
				else if(!Piers[2]) Piers[2] = 1, ShipCanMoveToPort2(2);
			}
		}
	}

	void LeavePier(int i) {
		Piers[i] = 0;
		if (i == 0) dock->refresh();
		else if (i == 1) flagShipInRedZone = false, berth1->refresh();
		else if (i == 2) flagShipInRedZone = false, berth2->refresh();
	}
};


